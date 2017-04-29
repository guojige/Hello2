#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <assert.h>

struct header
{
	int filelength;
	char filename[128];
};

int main(int argc, char *argv[])
{
	// 0 cmd argument
	if(argc != 4)
	{
		fprintf(stderr, "Usage:%s ip port file\n", argv[0]);
		return -1;
	}


	//1  socket: int socket(int domain, int type, int protocol);
	int servfd ;
	servfd = socket(AF_INET, SOCK_STREAM, 0);
	//if(servfd <=0 )
	assert(servfd>0);

	printf("servfd = %d\n", servfd);  // 3

#if 1
	//2  bind: int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
	struct sockaddr_in servaddr;
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(6678);   // > 1024
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	
	int ret = bind(servfd, (struct sockaddr *)&servaddr,  sizeof(struct sockaddr_in));
	assert(ret!=-1);
#endif
	// 3 connect: int connect(int sockfd, const struct sockaddr *addr,
	//                    socklen_t addrlen);
	struct sockaddr_in saddr;
	saddr.sin_family = AF_INET;
	saddr.sin_port = htons(atoi(argv[2]));   // > 1024
	saddr.sin_addr.s_addr =  inet_addr(argv[1]);  // "192.168.14.205"
	ret = connect(servfd, (struct sockaddr *)&saddr, sizeof(struct sockaddr_in));                   
	assert(ret!=-1);
	printf("suceessfull\n");

	FILE *fp = fopen(argv[3], "r");
	assert(fp != NULL);
	
	struct header info;
	info.filelength = //?;
	strcpy(info.filename, argv[3]);
	
	//write(newfd, &info , sizeof(info));
	send(newfd, &info , sizeof(info), 0);

	char buff[32];
	int cnt;
	while(1)
	{
		cnt = fread(buff, 1, 32, fp);
		if(cnt <=0)
			break;
		write(servfd, buff, cnt);
	}
	fclose(fp);
	close(servfd);

	return 0;
}
