#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	//1  socket: int socket(int domain, int type, int protocol);
	int servfd ;
	servfd = socket(AF_INET, SOCK_STREAM, 0);
	printf("servfd = %d\n", servfd);  // 3
	//2  bind: int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
	struct sockaddr_in servaddr;
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(6677);   // > 1024
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	bind(servfd, (struct sockaddr *)&servaddr,  sizeof(struct sockaddr_in));
	//3  listen:  int listen(int sockfd, int backlog);
	listen(servfd, 5);
//  --------------------------------------------------------------
	//4  accept:  int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
#if 0
	int newfd;
	printf("waiting for client....\n");
	newfd = accept(servfd, NULL, NULL);
	printf("suceessfull\n");
	while(1)
	{
		write(newfd, "helloworld", 11);
		sleep(3);
	}
	close(newfd);
#endif

#if 0
	int newfd;
	while(1)
	{
		printf("waiting for client....\n");
		newfd = accept(servfd, NULL, NULL);
		printf("suceessfull:%d\n",newfd);
		write(newfd, "helloworld", 11);
		sleep(3);
	}
	close(newfd);
#endif 
#if 1
	int newfd;
	char buff[128];
	int cnt;
while(1)
{
	printf("waiting for client....\n");
	newfd = accept(servfd, NULL, NULL);
	printf("suceessfull\n");
	while(1)
	{
		//write(newfd, "helloworld", 11);
		fgets(buff, 128, stdin);
		write(newfd, buff, strlen(buff)+1);
		bzero(buff, 128);
		cnt=read(newfd, buff, 128);
		if(cnt<=0)
			break;
		printf("%s\n", buff);
	}
	close(newfd);
}
#endif
	//6  write
	//7  close
	close(servfd);
	return 0;
}
