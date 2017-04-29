#include "socket_includes.h"
#include <unistd.h>
#include <fcntl.h>

#include <sys/epoll.h>
#include <errno.h>


extern int errno;  // 引用外部全局变量，错误原因

int mz_ipv4_tcp_create_socket(void)
{
	int listenfd, sockfd, opt = 1;
	struct sockaddr_in server, client;
	socklen_t len;
	int timep;
	int ret;

	listenfd = socket(AF_INET, SOCK_STREAM, 0);
	if(listenfd < 0){
		perror("Create socket fail.");
		return -1;
	} 
	// 套接字选项设置  ：  广播、多播、地址复用    assert( ret!= -1)--- 关闭服务器后可以立即启用
	if((ret = setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) < 0){
		perror("Error, set socket reuse addr failed");  
		return -1;
	}

	bzero(&server, sizeof(server));
	server.sin_family = AF_INET;
	server.sin_port   = htons(SERV_PORT);
	server.sin_addr.s_addr  = htonl(INADDR_ANY);
	
	len = sizeof(struct sockaddr);
	if(bind(listenfd, (struct sockaddr *)&server, len)<0){
			  perror("bind error.");
		return -1;
	}
	
	  
	listen(listenfd, MAX_LISTEN_QUE);

	return listenfd;
}


int mz_process_data(int sockfd)
{
	int bytes;
	char buf[100];
	char *s = buf;
	
	bytes = recv(sockfd, s, 100, 0);
	if(bytes < 0)
	{
		if(errno == EAGAIN){	
			printf("no data.\n");
		}
		perror("recv err:");
		return -1;
	}
	if(bytes == 0)	// client close
		return -2;
		
	printf("bytes:%d\n", bytes);
	printf("buf:%s\n", buf);
	send(sockfd, buf, bytes, 0);
	
	return 0;
}


int main(int argc, char *argv[])
{
	// 监听套接字 ， 客户端连接套接字
	int listenfd, sockfd;
	//  epoll句柄
	int epollfd, fds;
	//               事件    事件集合,通过它返回已经发生的事件
	struct epoll_event ev, events[MAX_EVENTS];	
	int i, rv;
	// 地址结构
	struct sockaddr_in client;
	int len;

	len = sizeof(struct sockaddr_in);
	epollfd = epoll_create(MAX_EVENTS);	// 创建句柄，句柄代表可以管理的epoll集（套接字集合）
	if(epollfd < 0){
		perror("epoll_create err:");
		return -1;
	}
	// 自定义封装函数 ： socket bind listren--创建监听套接字
	listenfd = mz_ipv4_tcp_create_socket();

	// fcntl函数，可以不写
	fcntl(listenfd, F_SETFL, O_NONBLOCK);  // 非阻塞

	ev.data.fd = listenfd;	// 关注哪个socket
	ev.events = EPOLLIN;	// 什么事件： 可读、数据可接收		--- 关注客户端连接事件
	rv = epoll_ctl(epollfd, EPOLL_CTL_ADD, listenfd, &ev);	// 把监听套接字事件添加到epollfd集合，进行统一管理
	if(rv < 0){
		perror("epoll_ctl err:");
		return -1;
	}


	while(1){
		//time_out
      printf("block waiting for client....\n");
		//  阻塞等待事件发生，如果epollfd这个集合中有任何一个socket可读，立即返回
		fds = epoll_wait(epollfd, events, MAX_EVENTS, -1);
		
		if(fds < 0){
			perror("epoll_wait err:");
			return -1;
		}
		
		// fds表示有几个事件发生了，  events 哪几个套接字事件
      printf("event numbers:%d\n", fds);
		for(i = 0; i < fds; i++){	// 遍历处理所有发生的事件
			if(events[i].data.fd == listenfd){	// 判断其中有没有新的连接
				sockfd = accept(listenfd, (struct sockaddr *)&client, &len);
				if(sockfd < 0){
					perror("accept err:");
					continue;
				}
					// 如果有新的连接，加入epollfd集合
				ev.data.fd = sockfd;
				ev.events = EPOLLIN | EPOLLET;
				epoll_ctl(epollfd, EPOLL_CTL_ADD, sockfd, &ev);
				printf("new client=%d\n", sockfd);
				continue;
			}else{
				rv = mz_process_data(events[i].data.fd);
				if(rv == -2){	// 客户端关闭连接，把它从epollfd中删除
					epoll_ctl(epollfd, EPOLL_CTL_DEL, events[i].data.fd, &ev);
					printf("client %d quit\n", events[i].data.fd);
					close(events[i].data.fd);
					continue;
				}
			}

		}
		


	}

}






