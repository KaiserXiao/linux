/*
 *DATA:		2016年3月24日22点
 *AUTHOR:		KaiserXiao
 *DESCRIPTION:	多线程TCP服务器
 * 1、int socket (int domain,int type, int protocol);
		domain:通信域，确定通信特性，包括地址格式
		type: 套接字类型
		protocol:相应的传输协议

*  2、int bind  (int socketfd,const struct socketaddr *addr ,strlen_t addrlen);
		socketfd:套接字socket
		*addr:服务器的ip地址
		addrlen:addr的长度

* 3、listen(int socketfd,int backlog)
		backlog:服务器接收的数量

* 4、int accept(int socketfd,struct sockaddr* addr, socklen_t *addrlen);
		同2

* 5、read、write

*/


#include "apue.h"
#define  MAX_LISTEN 10

char buf[128]={0};

int  main()
{
	struct sockaddr_in server_ip,remote_ip;
	int server_len,remote_len;
	
	int err,sd,ad;

	sd=socket(AF_INET,SOCK_STREAM,0);
	if(sd=-1)
	{
		printf("Create socket failed ,errno is %d\n",errno);
		close(sd);
		return 0;
	}

//bind
	//协议族
	server_ip.sin_family=AF_INET;
	//端口
	//将其从主机序转化为网络序htons
	server_ip.sin_port=htons(5678);
	
	//IP地址
	//htoml传入的参数INADDR_ANY一般情况下为0，传入后函数自动处理，将其变为IP地址，使程序更具可移植性
	server_ip.sin_addr.s_addr=htoml(INADDR_ANY);
	
	memset(&server_ip.sin_zero,0,8);

	err=bind(sd,(struct sockaddr *)(&server_ip),sizeof(struct sockaddr));
	if (err==-1)
	{
		printf("Bind Err,Errno is %d\n",errno);
		close(sd);
		return 0;
	}
	
	//监听
	err=listen (sd,MAX_LISTEN);
	if(err=-1)
	{
		printf("Listren Err,Errno is %d\n",errno);
		close(sd);
		return 0;
	}

	
	//接受新的SOCKET
	remote_len=sizeof(struct sockaddr);
	ad=accept(sd,(struct sockaddr *)(&remote_ip),&remote_len);
	if(ad==-1)	
	{
		printf("accept Error.Error is %d\n",errno);
		close(sd);
		close(ad);
		return 0;
	}

	read(ad,buf,128);
	printf("buf is %s\n",buf);

	close(sd);
	close(ad);


}	


