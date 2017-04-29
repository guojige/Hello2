#include <event.h>
#include <evdns.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <regex.h>
#include <sys/types.h>

#include <stdio.h>


//回调函数
static void callback(int result, char type, int count, int ttl, void *addresses, void *arg) 
{
	 struct in_addr *addrs = (struct in_addr *)addresses;
	 char * ip = inet_ntoa(addrs[0]);  //  点分十进制 <==   整型数据
	 printf("ipaddr:%s\n", ip);
}

#if  0

int main(int argc, char *argv[])
{

	struct event_base * base = event_init();
	evdns_init();
	evdns_resolve_ipv4(argv[1], 0, callback, NULL);// 当libevent解析结束后，调用callback
	event_dispatch();
	event_base_free(base);
	
	return 0;
}

#endif
