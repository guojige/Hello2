#include<stdio.h>  // printf scanf 
#include<stdlib.h> // exit
#include<string.h>  // strcpy strlen
#include<sys/socket.h>  // socket 
#include<netinet/in.h>  // struct sockaddr_in 
#include<arpa/inet.h>
#include <wiringPi.h>  // 硬件控制

int tcp_serv_init(int serv_port)	
{	
	int port = serv_port;
	// step1:创建套接字
	int servfd; // 套接字、文件描述符，  用于建立连接
			// AF_INET:协议族 ip+port， tcp
	servfd = socket(AF_INET, SOCK_STREAM, 0); // SOCK_DGRAM  ---- UDP
	// step2: 绑定地址
	struct sockaddr_in  servaddr;
	servaddr.sin_family= AF_INET;
	servaddr.sin_addr.s_addr = 	htonl(INADDR_ANY)	;  // 0.0.0.0 => 32位整数
	servaddr.sin_port =  htons(port);  //端口号 htons htonl
	int ret;
	//ret = bind(servfd, &servaddr, sizeof(servaddr));
	ret = bind(servfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
	if(ret < 0 )
	{
		printf("bind error\n");
		exit(1);  //退出程序
		
	}
	
	// step3: 监听
	listen(servfd, 5);  //把自己变成变动
	return servfd;
}

void led_init()
{
		
	pinMode(8, OUTPUT);   //D0
	pinMode(9, OUTPUT);		// R
	pinMode(7, OUTPUT);		//G
	pinMode(0, OUTPUT);		// B
	
	digitalWrite(9, HIGH);
	digitalWrite(7, HIGH);
	digitalWrite(0, HIGH);
	
}

int main()
{

	// 网络初始化
	int servfd = tcp_serv_init(1234);
	// 硬件初始化
	wiringPiSetup();
	// LED初始化
	led_init();
	
	// step4: 等待客户端的连接--一直等待
	int newfd; // 用于跟连接进来的客户端进行数据收发
	printf("waitng for client .......\n");
	newfd = accept(servfd, NULL, NULL); // 阻塞函数
	printf("client connect successful\n");
	
	
	///  服务器读 
	char str[1024];  //定义一个数组，用于接收网络字符串
	while(1)
	{	// 从网络读取数据，放到内存空间str中，空间大小是1024字节
		read(newfd, str, 1024);  //阻塞等待网络数据
		if(strcmp(str, "on") == 0)   //比较字符串
		{
			
		}
		else if(strcmp(str, "off") == 0)
		{
			
		}
		printf("%s\n", str);
	}
	close(newfd);
	close(servfd);	
	
	
	
	
	return 0;
}