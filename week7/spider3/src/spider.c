#include <stdio.h>
#include <sys/epoll.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <getopt.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "spider.h"
#include "qstring.h"
#include "url.h"

Config *g_conf;

void version()
{
    printf("Version: spider 1.0\n");
    exit(1);
}

void usage()
{
    printf("Usage: ./spider [Options]\n"
            "\nOptions:\n"
            "  -h\t: this help\n"
            "  -v\t: print spiderq's version\n"
            "  -d\t: run program as a daemon process\n\n");
    exit(1);
}

int main(int argc, void *argv[]) 
{

    int daemonized = 1;
    char ch;
#if 1
    /* 解析命令行参数 */
    while ((ch = getopt(argc, (char* const*)argv, "vhd")) != -1) {
        switch(ch) {
            case 'v':
                version();
                break;
            case 'd':
                daemonized = 1;
		printf("daemon\n");
                break;
            case 'h':
            case '?':
                usage();
				break;
            default:
			break;
        }
    }
#endif

    /* 解析日志 */
    g_conf = initconfig();
    loadconfig(g_conf);

   

    SPIDER_LOG(SPIDER_LEVEL_DEBUG, "spider begin\n");
	
    /* 添加爬虫种子 */

    if (g_conf->seeds == NULL) {
        SPIDER_LOG(SPIDER_LEVEL_ERROR, "We have no seeds!");
    } else {
		SPIDER_LOG(SPIDER_LEVEL_DEBUG, "Seed=%s\n", g_conf->seeds);
	
    }	
	display_modules( g_conf);

		
     int c = 0;
     char ** splits = strsplit(g_conf->seeds, ',', &c, 0);
	 
        while (c--) {
            Surl * surl = (Surl *)malloc(sizeof(Surl));
            surl->url = url_normalized(strdup(splits[c]));
            surl->level = 0;
            surl->type = TYPE_HTML;
            if (surl->url != NULL)
            {
            	push_surlqueue(surl);
                SPIDER_LOG(SPIDER_LEVEL_DEBUG, "Got url,%s\n", surl->url);
            }
        }

	int sock_rv;
    int sockfd;
	evso_arg narg;
	while(!is_surlqueue_empty())
	{
		urlparser(NULL);

		while(is_ourlqueue_empty())
			sleep(1);

		Url *ourl = (Url *)pop_ourlqueue();
		SPIDER_LOG(SPIDER_LEVEL_DEBUG, "begin get text/html, %s\n", ourl->ip);

		if ((sock_rv = build_connect(&sockfd, ourl->ip, ourl->port)) < 0) {
        	SPIDER_LOG(SPIDER_LEVEL_WARN, "Build socket connect fail: %s", ourl->ip);
        	return -1;
    	}
		SPIDER_LOG(SPIDER_LEVEL_DEBUG, "connect to %s,%d\n", ourl->ip, ourl->port);
		if ((sock_rv = send_request(sockfd, (void *)ourl)) < 0) {
        	SPIDER_LOG(SPIDER_LEVEL_WARN, "Send socket request fail: %s", ourl->ip);
        	return -1;
    	} 
		SPIDER_LOG(SPIDER_LEVEL_DEBUG, "send http get to %s,%d\n", ourl->ip, ourl->port);

		narg.fd = sockfd;
		narg.url = ourl;
		recv_response(&narg);
		
	}

	
	
	
    SPIDER_LOG(SPIDER_LEVEL_DEBUG, "Task done!");
   
    return 0;
}

