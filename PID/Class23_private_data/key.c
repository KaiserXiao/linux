#include "apue.h"

void *thread_fun1(void *arg)
{
	printf("thread 1 start \n");
	open ("1.c",O_RDWR);
	sleep(2);
	printf("thread One errno is %d\n",errno);
}


void *thread_fun2(void *arg)
{
	sleep(1);
	printf("thread 2 start \n");
	open ("t.c",O_RDWR);
	printf("thread Two errno is %d\n",errno);
}

int main()
{
	pthread_t tid1,tid2;
	
	if(pthread_create(&tid1,NULL,thread_fun1,NULL))
	{
		printf("create new thread ONE failed\n");
		return 0;
	}


	if(pthread_create(&tid2,NULL,thread_fun2,NULL))
	{
		printf("create new thread TWO failed\n");
		return 0;
	}
	
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
		
	return ;
}
