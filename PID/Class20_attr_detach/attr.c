#include "apue.h"
pthread_t tid;


void *thread_fun1(void *arg)
{
	printf("I`m thread 0x%x\n",pthread_self());
	return  (void*)1;
}


void *thread_fun2(void *arg)
{
	printf("I`m thread 0x%x\n",pthread_self());
	return  (void*)1;
}


int main()
{
	pthread_t tid1,tid2;
	int err;
	//定义属性变量
	pthread_attr_t attr;
	//初始化
	pthread_attr_init (&attr);
	//设置为已经分离
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
	
	//改为可连接	
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_JOINABLE);
	err=pthread_create(&tid1,&attr,thread_fun1,NULL);
	if(err)
	{
		printf("Create Fail\n");
		return 0;
	}


	err=pthread_create(&tid2,NULL,thread_fun2,NULL);
	if(err)
	{
		printf("Create Fail\n");
		return 0;
	}
	
	if(!pthread_join(tid1,NULL))
		printf("One Join Success\n");
	else	
		printf("One Join Fail\n");

	if(!pthread_join(tid2,NULL))
		printf("Two Join Success\n");
	else	
		printf("Two Join Fail\n");
	
	//记得销毁	
	pthread_attr_destroy(&attr);
	return 0;
}
