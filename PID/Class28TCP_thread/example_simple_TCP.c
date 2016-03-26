#include "apue.h"
#define  MAX_LISTEN 10

char buf[128];
int ad[10];
struct sockaddr_in server_ip,remote_ip;

void *thread_fun(void *arg)
{
	while(1)
	{
		printf("I`m the client %d\n",(int)arg);
		printf("From Client %s\n",inet_ntoa(remote_ip.sin_addr));
		printf("sizeof buf is %d\n",sizeof(buf));
		read(ad[(int)arg],buf,sizeof(buf));
		printf("buf is %s\n",buf);
	}
}



int  main()
{
	int server_len,remote_len;
	pthread_t tid[10];
	
	int err,sd;
	int i=0;

	sd=socket(AF_INET,SOCK_STREAM,0);
	if(sd==-1)
	{
		printf("Create socket failed ,errno is %d\n",errno);
		close(sd);
		return 0;
	}

//以下为服务器网络设置
#if 1
	//协议族
	server_ip.sin_family=AF_INET;

	//端口
	//将其从主机序转化为网络序htons
	server_ip.sin_port=htons(5678);

	//IP地址
	//htoml传入的参数INADDR_ANY一般情况下为0，传入后函数自动处理，将其变为IP地址，使程序更具可移植性
	server_ip.sin_addr.s_addr=htonl(INADDR_ANY);

	//sin_zero 需要置零
	memset(&server_ip.sin_zero,0,8);
	
#endif

	//bind 将IP地址和socket连接在一起
	err=bind(sd,(struct sockaddr *)(&server_ip),sizeof(struct sockaddr));
	if (err==-1)
	{
		printf("Bind Err,Errno is %d\n",errno);
		close(sd);
		return 0;
	}
	
	//监听
	err=listen (sd,MAX_LISTEN);
	if(err==-1)
	{
		printf("Listren Err,Errno is %d\n",errno);
		close(sd);
		return 0;
	}

	
	//接受新的SOCKET、accept
	remote_len=sizeof(struct sockaddr);

	while (1)
	{
		printf("Create ad[%d] now\n",i);
		ad[i]=accept(sd,(struct sockaddr *)(&remote_ip),&remote_len);
		printf("Have accept the ad[%d] \n",i);
		if(ad[i]==-1)	
		{
			printf("accept Error.Error is %d\n",errno);
			close(ad[i]);
			close(sd);
			return 0;
		}
//这里没有pthread_join，没有sleep
//线程为什么会运行？
//猜测while起了作用
//但实际上很难预测
//	while(1){
//网上的资料说create时已经在运行
//试试死循环一个printf来试试
		err=pthread_create(&tid[i],NULL,thread_fun,(void *)i);
		if (err)
		{
			printf("Create pthread fail \n");
			close(ad[i]);
			close(sd);
		}
		printf("Pthread create tid[%d]\n",i);
		i++;
		while(1)
		{
			i++;
			printf("i is %d\n",i);
		}
	}

	close(sd);
	close(ad[i]);


}	


