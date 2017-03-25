#include<stdio.h>  // printf scanf 
#include<stdlib.h> // exit
#include<string.h>  // strcpy strlen
#include<sys/socket.h>  // socket 
#include<netinet/in.h>  // struct sockaddr_in 
#include<arpa/inet.h>

int main()
{
	// step1:创建套接字
	int clientfd; // 套接字、文件描述符，  用于建立连接
			// AF_INET:协议族 ip+port， tcp
	clientfd = socket(AF_INET, SOCK_STREAM, 0); // SOCK_DGRAM  ---- UDP
	
	/*
		// step2: 绑定地址
	struct sockaddr_in  servaddr;
	servaddr.sin_family= AF_INET;
	servaddr.sin_addr.s_addr = 	htonl(INADDR_ANY)	;  // 0.0.0.0 => 32位整数
	servaddr.sin_port =  htons(4543);  //端口号 htons htonl
	int ret;
	//ret = bind(servfd, &servaddr, sizeof(servaddr));
	ret = bind(servfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
	if(ret < 0 )
	{
		printf("bind error\n");
		exit(1);  //退出程序
		
	}
	*/
	
	// step3: 定义服务器地址，主动建立
	struct sockaddr_in  myservaddr;
	myservaddr.sin_family = AF_INET;
	myservaddr.sin_addr.s_addr = inet_addr("127.0.0.1");  // 本地还回 把点分十进制转换32位整数
					// 172.16.126.2    192.168.1.200
	myservaddr.sin_port = htons(1234);				
	connect(clientfd, &myservaddr, sizeof(myservaddr));
	
	
	///  客户端 写  
	char str[1024];
	while(1)
	{
		scanf("%s", str);
		// 发送给服务器  
		write(clientfd, str, strlen(str)+1);   // 求字符串长度   \0
	}
	close(clientfd);
	
	return 0;
}








