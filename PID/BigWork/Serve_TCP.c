/*

 * Data:	16:3:25:17
 * author:	KaiserXiao
 * DESCRIPTION:
   	握手服务器
   	发信息
   	收信息
   	
 * DETAIL:
 	Socket_Init:
		Create_Socket:
			socket()
 	  	Set_IP&Port:
			
		Connect_Server
	Get&write_Data
	Send_Data
	Close
	
 */

#include "apue.h"
#define MAX_LIS_NUM 10

void *thread_write(void * socket_ad);
void *thread_read(void * socket_ad );
int  Socket_Init(void);
void Set_Config(struct sockaddr_in *IP);
void Close(int socket_sd,int accpet_id);
void Bind_ip_socket(int socket_sd,struct sockaddr_in *IP);
void Listen_socket(int socket_sd);
int Accept_socket(int socket_sd,struct sockaddr_in *IP);

int main()
{
	int err,sd,tid1,tid2,ad;
	struct sockaddr_in IP;	
	sd=Socket_Init();
	Set_Config(&IP);
	Bind_ip_socket(sd,&IP);
	Listen_socket(sd);
	ad=Accept_socket(sd,&IP);
	pthread_create(&tid1,NULL,thread_write,(void*)ad);
	pthread_create(&tid2,NULL,thread_read,(void *)ad);
	Close(sd,ad);
}



int Socket_Init(void)
{
	int sd;
	sd=socket(AF_INET,SOCK_STREAM,0);
	if (sd==-1)
	{
		printf("Create socket fail,ERRNO is %d\n",errno);
		close(sd);
		return -1;
	}
		
	return sd;
}

void Set_Config(struct sockaddr_in *IP)
{
	(*IP).sin_family=AF_INET;
	(*IP).sin_port=htons(5678);
	(*IP).sin_addr.s_addr=htonl(INADDR_ANY);
	memset((*IP).sin_zero,0,8);
}


void Bind_ip_socket(int socket_sd,struct sockaddr_in *IP)
{
	if(bind(socket_sd,(struct sockaddr *)IP,sizeof(struct sockaddr))==-1)
	{
		printf("Bind Err.Errno is %d\n",errno);
		return -1;
	}
}


void Listen_socket(int socket_sd)
{
	if(listen(socket_sd,MAX_LIS_NUM)==-1)
	{
		printf("Listen fail.The errno is %d\n",errno);
		return -1;
	}
}

int  Accept_socket(int socket_sd,struct sockaddr_in *IP)
{
	int len,ad;
	printf("Accept ...");
	len=sizeof(struct sockaddr);
	ad=accept(socket_sd,(struct sockaddr *)IP,&len);
	if(ad==-1)
	{
		printf("Accpet Error.Errno is %d\n",errno);
		close(ad);
		close(socket_sd);
		return -1;
	}
	return ad;
}


void *thread_write(void  *socket_ad)
{
	while(1)
	{
		printf("Send ..\n");
		write((int)socket_ad,"buffer",6);
		sleep(1);
	}
}

void *thread_read(void *socket_ad )
{	
	char buf[128];
	while(1)
	{
		printf("Receive..\n");
		read((int) socket_ad,buf,sizeof(buf));
		printf("Client 2 say %s\n",buf);
		sleep(1);
	}
}
void Close(int socket_sd,int accept_id)
{
	close(accept_id);
	close(socket_sd);
}

