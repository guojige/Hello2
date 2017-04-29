#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

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
	//4  accept:  int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
	int newfd;
	printf("waiting for client....\n");
	newfd = accept(servfd, NULL, NULL);
	printf("suceessfull\n");
	while(1)
	{
		write(newfd, "helloworld", 11);
		sleep(3);
	}
	//5  read 
	//6  write
	//7  close

	return 0;
}
