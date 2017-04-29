#ifndef QURL_H
#define QURL_H
 
#include <event.h>
#include <evdns.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <regex.h>
#include <sys/types.h>

/*
#include <queue>
#include <map>
#include <string>
#include "spider.h"
*/
/*
#include <event2/bufferevent.h>
#include <event2/buffer.h>
#include <event2/listener.h>
#include <event2/util.h>
#include <event2/event.h>
*/

#include "bloomfilter.h"
#include "klist.h"




#define MAX_LINK_LEN 128

#define TYPE_HTML  0
#define TYPE_IMAGE 1

typedef struct Surl {
    char  *url;
    int    level;
    int    type;
} Surl;

typedef struct Url {
    char *domain;
    char *path;
    int  port;
    char *ip;
    int  level;
} Url;

typedef struct _queue{
	int length;
	struct list_head  qhead;
}queue;	// 工作队列


//可以考虑使用联合体类型
union url_type
{
	Surl *surl;
	Url *url;
};

typedef struct _queue_node
{
	int type;		//  1:Surl  2:Url
	//存放数据节点的指针，malloc注销释放
	union url_type purl;		//if 1  purl.surl = ...   if 2 purl.url = ...
	struct list_head link;
}queue_node;


typedef struct evso_arg {
    int     fd;		
    Url     *url;
} evso_arg;


extern queue *queue_init(void);
extern void push_surlqueue(Surl * url);
extern Surl * pop_surlqueue();
extern Url * pop_ourlqueue();
extern void * urlparser(void * arg);
extern char * url_normalized(char *url);
extern void free_url(Url * ourl);
extern int is_ourlqueue_empty();
extern int is_surlqueue_empty();
extern int get_surl_queue_size();
extern int get_ourl_queue_size();


#endif
