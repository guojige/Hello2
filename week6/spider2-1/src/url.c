#include "url.h"
#include "spider.h"
#include <time.h>
#include <ctype.h>

#include "uthash.h"

typedef struct my_struct {  
    char domain[128];             /* key (string is WITHIN the structure) */  
    char ip[32]; 
    UT_hash_handle hh;         /* makes this structure hashable */  
}hashmap;  

  
hashmap *domain_ip_map;


static queue surl_queue;
static queue ourl_queue;
//static map<string, string> host_ip_map;

void hash_add(char *domain, char *ip)
{
	hashmap *s = (hashmap*)malloc(sizeof(hashmap));  
	strcpy(s->domain, domain);  
	strcpy(s->ip, ip);	
	HASH_ADD_STR( domain_ip_map, domain, s );  
}

char * hash_find(char *domain)
{
	hashmap *s=NULL;
	HASH_FIND_STR( domain_ip_map, domain, s);  
	if(s)
		return s->ip;
	else 
		return NULL;
}


void hash_destroy()
{
	  hashmap *s, *tmp;
	  HASH_ITER(hh, domain_ip_map, s, tmp) 
	  {  
      	HASH_DEL(domain_ip_map, s);  
      	free(s);  
      }  
}

static Url * surl2ourl(Surl *url);
static void dns_callback(int result, char type, int count, int ttl, void *addresses, void *arg);
static int surl_precheck(Surl *surl);
static void get_timespec(struct timespec * ts, int millisecond);


queue *queue_init(void)
{
	queue *wk;
	wk = (queue *)malloc(sizeof(queue));
	if(NULL == wk){
		perror("queue_init malloc");
		exit(1);
	}
	INIT_LIST_HEAD(&wk->qhead);
	wk->length = 0;
	return wk;
}


void  enqueue(queue *wk, Surl *surl, Url *ourl)
{
	queue_node *newnode = (queue_node *)malloc(sizeof(queue_node));
	if(NULL == newnode){
		perror("malloc");
		exit(1);
	}
	INIT_LIST_HEAD(&newnode->link);
	
	if(wk->length ==0)
		INIT_LIST_HEAD(&wk->qhead);
	
	if(surl!=NULL)
	{
		newnode->type = 1;
		//newnode->purl.surl = (char *)malloc(strlen(surl)+1);
		//strcpy(newnode->purl.surl, surl);
		newnode->purl.surl = surl;	
	}
	else if(ourl!=NULL)
	{
		newnode->type = 2;
		//newnode->purl.url = (char *)malloc(strlen(url)+1);
		//strcpy(newnode->purl.url, url);
		newnode->purl.url = ourl;
	}
	else 
		return ;
	
	list_add_tail(&newnode->link, &wk->qhead);  // 右结合
	wk->length++;
	//puts("OK");
	return ;
}
void *dequeue(queue *wk)
{
	void *data;
	queue_node *qnode;
	
	if(list_empty(&wk->qhead))
		return NULL;
	
	struct list_head *qhead = &wk->qhead;   // 队列的头
	
	struct list_head *nodelink = qhead->next;	// 第一个链表结点
	
	//list_entry(ptr, type, member)
	qnode = list_entry(nodelink, queue_node, link);
	//printf("OK %d\n", qnode->arg);
	list_del_init(&qnode->link);
	wk->length--;
	
	if(qnode->type==1)
	{
		data = qnode->purl.surl;
	}
	else
	{
		data = qnode->purl.url;
	}
	
	free(qnode);
	
	return data; 
}


void push_surlqueue(Surl *surl)
{
    if (surl != NULL && surl_precheck(surl)) {
        SPIDER_LOG(SPIDER_LEVEL_DEBUG, "%s,%s,%d\n", __FILE__, __FUNCTION__, __LINE__);
		//DEBUG_FLOW();
		enqueue(&surl_queue, surl, NULL);
    }
}

Surl * pop_surlqueue()
{
	if(is_surlqueue_empty())
		return NULL;
	DEBUG_FLOW();
	return (Surl*)dequeue(&surl_queue);
}

Url * pop_ourlqueue()
{
	if(is_ourlqueue_empty())
		return NULL;
	DEBUG_FLOW();
	return (Url*)dequeue(&ourl_queue);
}

static void get_timespec(struct timespec * ts, int millisecond)
{
    struct timeval now;
    gettimeofday(&now, NULL);
    ts->tv_sec = now.tv_sec;
    ts->tv_nsec = now.tv_usec * 1000;
    ts->tv_nsec += millisecond * 1000;
}

static int surl_precheck(Surl *surl)
{	//预处理原始url
	/*
    unsigned int i;
    for (i = 0; i < modules_pre_surl.size(); i++) {
        if (modules_pre_surl[i]->handle(surl) != MODULE_OK)
            return 0;
    }*/
    return 1;
}

static void push_ourlqueue(Url * ourl)
{
	if (ourl != NULL)
	{
		SPIDER_LOG(SPIDER_LEVEL_DEBUG, "ourl: %s\n", ourl->ip);
		enqueue(&ourl_queue, NULL, ourl);
	}
}

int is_ourlqueue_empty() 
{
    int val = ourl_queue.length;
    if(val == 0)
		return 1;
	else 
		return 0;
	
	// return list_empty(&ourl_queue.qhead);
}

int is_surlqueue_empty() 
{
	int val = surl_queue.length;
    if(val == 0)
		return 1;
	else 
		return 0;
	// return list_empty(&surl_queue.qhead);
}

void * urlparser(void *none)
{
    Surl *surl = NULL;
    Url  *ourl = NULL;
    //map<string, string>::const_iterator itr;
    //event_base * base = event_base_new();
    //evdns_base * dnsbase = evdns_base_new(base, 1);
    //event_base_loop(base,EVLOOP_NONBLOCK);

	if(is_surlqueue_empty())
		return NULL;
	
	
	surl = (Surl*)pop_surlqueue();
       
    ourl = surl2ourl(surl);

	char *ip = hash_find(ourl->domain);
	if(NULL == ip)
	{
	    //itr = host_ip_map.find(ourl->domain);  //判断该域名已经转换过了
	       
	            /* dns resolve */
	    struct event_base * base = event_init();
	    evdns_init();
	    evdns_resolve_ipv4(ourl->domain, 0, dns_callback, ourl);
	    event_dispatch();
	    event_base_free(base);
	}
	else
	{
		SPIDER_LOG(SPIDER_LEVEL_DEBUG,"use old dns\n");
		ourl->ip = strdup(ip);
		push_ourlqueue(ourl);
	}
    //evdns_base_free(dnsbase, 0);
    //event_base_free(base);
    return NULL;
}


static void dns_callback(int result, char type, int count, int ttl, void *addresses, void *arg) 
{
    Url * ourl = (Url *)arg;
    struct in_addr *addrs = (struct in_addr *)addresses;

    if (result != DNS_ERR_NONE || count == 0) {
        SPIDER_LOG(SPIDER_LEVEL_WARN, "Dns resolve fail: %s", ourl->domain);
    } else {
        char * ip = inet_ntoa(addrs[0]);
        SPIDER_LOG(SPIDER_LEVEL_DEBUG, "Dns resolve OK: %s -> %s", ourl->domain, ip);
        //host_ip_map[ourl->domain] = strdup(ip);
        
        ourl->ip = strdup(ip);
		hash_add(ourl->domain, ourl->ip);
        push_ourlqueue(ourl);
    }
    event_loopexit(NULL); // not safe for multithreads 
}

static Url * surl2ourl(Surl * surl)
{
    Url *ourl = (Url *)calloc(1, sizeof(Url));
    char *p = strchr(surl->url, '/');   
    if (p == NULL) {
        ourl->domain = surl->url;	// domain
        ourl->path = surl->url + strlen(surl->url); // path
    } else {
        *p = '\0';
        ourl->domain = surl->url;
        ourl->path = p+1;
    }
    // port
    p = strrchr(ourl->domain, ':');
    if (p != NULL) {
        *p = '\0';
        ourl->port = atoi(p+1);
        if (ourl->port == 0)
            ourl->port = 80;

    } else {
        ourl->port = 80;
    }
    // level
    ourl->level = surl->level;
    return ourl;
}

char * url_normalized(char *url) 
{
    if (url == NULL) return NULL;

    /* rtrim url */
    int len = strlen(url);
    while (len && isspace(url[len-1]))
        len--;
    url[len] = '\0';

    if (len == 0) {
        free(url);
        return NULL;
    }

    /* remove http(s):// */
    if (len > 7 && strncmp(url, "http", 4) == 0) {
        int vlen = 7;
        if (url[4] == 's') /* https */
            vlen++;

        len -= vlen;
        char *tmp = (char *)malloc(len+1);
        strncpy(tmp, url+vlen, len);
        tmp[len] = '\0';
        free(url);
        url = tmp;
    }

    /* remove '/' at end of url if have */
    if (url[len-1] == '/') {
        url[--len] = '\0';
    }

    if (len > MAX_LINK_LEN) {
        free(url);
        return NULL;
    }

    return url;
}


void free_url(Url * ourl)
{
    free(ourl->domain);
    //free(ourl->path);
    free(ourl->ip);
    free(ourl);
}

int get_surl_queue_size()
{
    return surl_queue.length;
}

int get_ourl_queue_size()
{
    return ourl_queue.length;
}





