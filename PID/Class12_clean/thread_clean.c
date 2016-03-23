#include "apue.h"

void *first_clean(void *arg)
{
	printf("%s first clean \n",(char *)arg);
	return (void *)0;
}


void *second_clean(void *arg)
{
	printf("%s second  clean \n",(char *)arg);
	return (void *)0;
}

void *thread_fun1(void *arg)
{
	printf("New thread 1\n");
	pthread_cleanup_push(first_clean,"thread ONE");
	pthread_cleanup_push(second_clean,"thread ONE");
	
	pthread_cleanup_pop(1);
	pthread_cleanup_pop(0);
	
	return (void *)1;
}


void *thread_fun2(void *arg)
{
	printf("New thread 2\n");
	pthread_cleanup_push(first_clean,"thread TWO");
	pthread_cleanup_push(second_clean,"thread TWO");

	//调用pthread_exit立马响应退出函数	
	pthread_exit((void *)2);
	pthread_cleanup_pop(0);
	pthread_cleanup_pop(0);

}
int main()
{
	pthread_t tid1,tid2;
	int err;

	err=pthread_create(&tid1,NULL,thread_fun1,NULL);
	if(err)
	{
		printf("Create One Fail\n");	
		return 0;
	}


	err=pthread_create(&tid2,NULL,thread_fun2,NULL);
	if(err)
	{
		printf("Create Two  Fail\n");	
		return 0;
	}

	sleep(2);
	return 0;
}
