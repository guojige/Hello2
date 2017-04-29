#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <assert.h>
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
	int ret=bind(servfd, (struct sockaddr *)&servaddr,  sizeof(struct sockaddr_in));
	assert(ret != -1);
	//3  listen:  int listen(int sockfd, int backlog);
	listen(servfd, 5);

	//******************************************************************

	//4  accept:  int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
	int newfd;
	fd_set iofds;
	int maxfd;
	maxfd = servfd + 1;
	int fdarr[1024] = {0};
	int i;

	char buff[128];
	int cnt;

	while(1)
	{
		FD_ZERO(&iofds);
		FD_SET(servfd, &iofds);
		for(i=0; i<1024; i++)
		{
			if(fdarr[i] != 0)
			{
				FD_SET(fdarr[i], &iofds);
				if(maxfd <= fdarr[i])
					maxfd = fdarr[i] + 1;
			}
		}

		printf("waiting for conncting or message ....\n");
		select( maxfd, &iofds, NULL, NULL, NULL);
		printf("something change\n");
		if(FD_ISSET(servfd, &iofds))
		{
			printf("begin to accept new client\n");
			newfd = accept(servfd, NULL, NULL);
			printf("newfd = %d\n", newfd);
			for(i=0; i<1024; i++)
			{
				if(fdarr[i] == 0)
				{
					fdarr[i] = newfd;
					break;
				}
			}
		}

		for(i=0; i<1024; i++)
		{
			if(fdarr[i] !=0 && FD_ISSET(fdarr[i], &iofds))
			{
				cnt = read(fdarr[i], buff, 128);
				if(cnt <=0)
				{
					close(fdarr[i]);
					fdarr[i] = 0;
				}
				printf("newfd=%d, %s\n", fdarr[i], buff);
			}
		}
			
	}	
	
	close(servfd);
	return 0;
}
