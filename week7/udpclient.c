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
	servfd = socket(AF_INET, SOCK_DGRAM, 0);
	printf("servfd = %d\n", servfd);  // 3

#if 0
	//2  bind: int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
	struct sockaddr_in servaddr;
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(6678);   // > 1024
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	bind(servfd, (struct sockaddr *)&servaddr,  sizeof(struct sockaddr_in));
#endif
	struct sockaddr_in saddr;
	saddr.sin_family = AF_INET;
	saddr.sin_port = htons(6677);   // > 1024
	//saddr.sin_addr.s_addr =  inet_addr("127.0.0.1");  // "192.168.14.205"
	saddr.sin_addr.s_addr =  inet_addr("192.168.14.205");  // "192.168.14.205"
	
	char buff[128];
	int cnt;
	while(1)
	{
		fgets(buff, 128, stdin);
		sendto(servfd, buff, strlen(buff)+1, 0, 
				(struct sockaddr*)&saddr, sizeof(saddr));
		memset(buff, 128, 0);
		recvfrom(servfd, buff, 128, 0, NULL, NULL);
		puts(buff);
	}

	//7  close
	close(servfd);
	return 0;
}
