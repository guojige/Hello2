#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
int main()
{
	//1  socket: int socket(int domain, int type, int protocol);
	int servfd ;
	servfd = socket(AF_INET, SOCK_DGRAM, 0);
	printf("servfd = %d\n", servfd);  // 3
	//2  bind: int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
	struct sockaddr_in servaddr;
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(6677);   // > 1024
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	bind(servfd, (struct sockaddr *)&servaddr,  sizeof(struct sockaddr_in));
	char buff[128];

	struct sockaddr_in  peer;
	socklen_t  peerlen;
	int cnt;

	while(1)
	{
		// 3 ssize_t recvfrom(int sockfd, void *buf, size_t len, int flags,
		//                         struct sockaddr *src_addr, socklen_t *addrlen);
		memset(&peer, sizeof(peer), 0);
		peerlen = sizeof(peer);
		// bzero(&peer, sizeof(peer));
		cnt = recvfrom(servfd, buff, 128, 0, (struct sockaddr *)&peer, &peerlen);
		printf("port:%d\n", ntohs(peer.sin_port));
		printf("ip:%s\n", inet_ntoa(peer.sin_addr));

		//4 ssize_t sendto(int sockfd, const void *buf, size_t len, int flags,
		//               const struct sockaddr *dest_addr, socklen_t addrlen);

		sendto(servfd, buff, cnt, 0, (struct sockaddr *)&peer, sizeof(peer));
		
	}
	//5  close();
	close(servfd);

	return 0;
}
