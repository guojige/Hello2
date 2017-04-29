#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <assert.h>
#include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>


struct header
{
	int filelength;
	char filename[128];
};


int main(int argc, char *argv[])
{
	// 0  
	if(argc !=2 )
	{
		fprintf(stderr, "Usage %s port\n", argv[0]);
		return -1;
	}

	//1  socket: int socket(int domain, int type, int protocol);
	int servfd ;
	servfd = socket(AF_INET, SOCK_STREAM, 0);
	assert(servfd >0);
	printf("servfd = %d\n", servfd);  // 3
	//2  bind: int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
	struct sockaddr_in servaddr;
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(atoi(argv[1]));   // > 1024
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	int ret = bind(servfd, (struct sockaddr *)&servaddr,  sizeof(struct sockaddr_in));
	assert(ret != -1);
	//3  listen:  int listen(int sockfd, int backlog);
	ret = listen(servfd, 5);
	assert(ret != -1);
	//4  accept:  int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
	int newfd;
	char buff[32];
	int cnt;

	struct header info;
	recv(servfd, &info, sizeof(info), 0);


	int filefd = open(info.filename, O_WRONLY | O_CREAT);
	int total = 0;

	printf("waiting for client....\n");
	newfd = accept(servfd, NULL, NULL);
	printf("suceessfull\n");
	while(1)
	{	
		cnt  = read(newfd, buff, 32);
		if(cnt <=0)
			break;
		total += cnt;
		write(filefd, buff, cnt);		
	}

	//if(tatal == info.filelength)

	

	close(newfd);
	close(filefd);
	close(servfd);
	return 0;
}
