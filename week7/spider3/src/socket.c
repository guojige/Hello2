#include <sys/socket.h>
#include <pthread.h>
#include <errno.h>
#include <fcntl.h>
#include "spider.h"
#include "url.h"
#include "socket.h"
#include "qstring.h"

extern int errno;
 
/* regex pattern for parsing href */
static const char * HREF_PATTERN = "href=\"\\s*\\([^ >\"]*\\)\\s*\"";

/* convert header string to Header object */
static Header * parse_header(char *header);

/* call modules to check header */
static int header_postcheck(Header *header);

int build_connect(int *fd, char *ip, int port)
{
    struct sockaddr_in server_addr;
    bzero(&server_addr, sizeof(struct sockaddr_in));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    if (!inet_aton(ip, &(server_addr.sin_addr))) {
        return -1;
    }

    if ((*fd = socket(PF_INET, SOCK_STREAM, 0)) < 0) {
        return -1;
    }

    if (connect(*fd, (struct sockaddr *)&server_addr, sizeof(struct sockaddr_in)) < 0) {
        close(*fd);
        return -1;
    }

    return 0;
}

int send_request(int fd, void *arg)
{
    int need, begin, n;
    char request[1024] = {0};
    Url *url = (Url *)arg;
	// printf  fprintf  sprintf 
	// http://www.baidu.com/s/xxx.html
    sprintf(request, "GET /%s HTTP/1.0\r\n"
            "Host: %s\r\n"
            "Accept: */*\r\n"
            "Connection: Keep-Alive\r\n"
            "User-Agent: Mozilla/5.0 (compatible; Qteqpidspider/1.0;)\r\n"
            "Referer: %s\r\n\r\n", url->path, url->domain, url->domain);

    need = strlen(request);
    begin = 0;
    while(need) {
        n = write(fd, request+begin, need);  // n<need   (need - n)
        if (n <= 0) {
            if (errno == EAGAIN) { //write buffer full, delay retry
                usleep(1000);
                continue;
            }
            SPIDER_LOG(SPIDER_LEVEL_WARN, "Thread %lu send ERROR: %d", pthread_self(), n);
            free_url(url);
            close(fd);
            return -1;
        }
        begin += n;
        need -= n;
    }
    return 0;
}

void set_nonblocking(int fd)
{
    int flag;
    if ((flag = fcntl(fd, F_GETFL)) < 0) {
        SPIDER_LOG(SPIDER_LEVEL_ERROR, "fcntl getfl fail");
    }
    flag |= O_NONBLOCK;
    if ((flag = fcntl(fd, F_SETFL, flag)) < 0) {
        SPIDER_LOG(SPIDER_LEVEL_ERROR, "fcntl setfl fail");
    }
}



#define HTML_MAXLEN   1024*1024




void * recv_response(void * arg)
{

	int n;
	int len;  // read bytes
	int trunc_head = 0;  // spilte
	char *body_ptr = NULL;
	//char buff[];
	evso_arg *narg = (evso_arg *)arg;
	Response *resp = (Response *)malloc(sizeof(Response));
	// if (resp == NULL)
	resp->header = NULL;
	resp->body = (char*)malloc(HTML_MAXLEN);
	resp->body_len = 0;
	resp->url = narg->url;

	int i;
	
    while(1)
    {
		n = read(narg->fd,  resp->body+len, 1024);
		//len += n;
		if(n<0)
		{//error		extern int errno;
			if(errno==EAGAIN || errno == EWOULDBLOCK || errno == EINTR)
			{
				usleep(100000);
				continue;
			}
			SPIDER_LOG(SPIDER_LEVEL_WARN, 
				"Read socket failed:%s", strerror(errno));
			break;
		}
		else if(n==0)
		{// finish reading
			resp->body_len = len;
			if(resp->body_len>0)
			{
				SPIDER_LOG(SPIDER_LEVEL_DEBUG, 
					"Read socket end, body size = %d\n",resp->body_len);
			}
			// save html
			//  parser html
			
			break;
		}
		else 	// n > 0
		{
			len += n;
			resp->body[len] = '\0';
			//  header + data
			if(trunc_head == 0) // 之前没有截取头
			{
				// char *strstr(const char *haystack, const char *needle);
				body_ptr = strstr(resp->body, "\r\n\r\n");
				if(body_ptr == NULL)
					continue;
				*(body_ptr+2) = '\0';
				resp->header = parse_header(resp->body);
				
				trunc_head = 1;
				SPIDER_LOG(SPIDER_LEVEL_DEBUG, 
					"stauts code:%d,content-type:%s\n", 
					resp->header->status_code,
					resp->header->content_type);

				//cover header
				body_ptr += 4;
				for(i=0; *body_ptr != '\0'; i++)
				{
					resp->body[i] = *body_ptr;
					body_ptr++;
				}
				resp->body[i] = '\0';
				len = i;
			}
			
			
		}
	}

  
    return NULL;
}

/*
static int header_postcheck(Header *header)
{
    unsigned int i;
    for (i = 0; i < modules_post_header.size(); i++) {
        if (modules_post_header[i]->handle(header) != MODULE_OK)
            return 0;
    }
    return 1;
}

*/


static Header * parse_header(char *header)
{
    int c = 0;
    char *p = NULL;
    char **sps = NULL;
    char *start = header;
    Header *h = (Header *)calloc(1, sizeof(Header));

    if ((p = strstr(start, "\r\n")) != NULL) {
        *p = '\0';
        sps = strsplit(start, ' ', &c, 2);
        if (c == 3) {
            h->status_code = atoi(sps[1]);
        } else {
            h->status_code = 600; 
        }
        start = p + 2;
    }

    while ((p = strstr(start, "\r\n")) != NULL) {
        *p = '\0';
        sps = strsplit(start, ':', &c, 1);
        if (c == 2) {
            if (strcasecmp(sps[0], "content-type") == 0) {
                h->content_type = strdup(strim(sps[1]));
            }
        }
        start = p + 2;
    }
    return h;
}


