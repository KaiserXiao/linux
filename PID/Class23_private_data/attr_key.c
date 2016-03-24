#include "apue.h"

pthread_key_t key;

void *thread_fun1(void *arg)
{
	printf("thread ONE start\n");
	int a=1;
	pthread_setspecific(key,(void *)a);
	sleep(2);
	printf("Thread One Key->data is %d\n",pthread_getspecific(key));
}

void *thread_fun2(void *arg)
{
	sleep(1);
	printf("thread TWO start\n");
	int a=2;
	pthread_setspecific(key,(void *)a);
	printf("Thread Two Key->data is %d\n",pthread_getspecific(key));
}

int main()
{
	pthread_t tid1,tid2;
	
	//初始化，形参（位置，虚构函数）
	pthread_key_create(&key,NULL);
	
	if(pthread_create(&tid1,NULL,thread_fun1,NULL))
	{
		printf("Create thread One Fail\n");
		return  0;
	}


	if(pthread_create(&tid2,NULL,thread_fun2,NULL))
	{
		printf("Create thread Two Fail\n");
		return  0;
	}

	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	pthread_key_delete(&key);
	return 1;
}
