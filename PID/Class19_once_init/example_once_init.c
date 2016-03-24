#include "apue.h"
//pthread_once_t once=1，其他线程初始化中
//pthread_once_t once=0，未曾初始化
//pthread_once_t once=2，已经初始化过
pthread_once_t once=1;
//pthread_once_t once=PTHREAD_ONCE_INIT;
pthread_t tid;

void thread_init()
{
	printf("I`m in thread 0x%x\n",tid);
}

void *thread_fun1(void *arg)
{
	tid=pthread_self();
	printf("I`m thread 0x%x\n",tid);
	printf("One Once is %d\n",once);
	pthread_once(&once,thread_init);
	printf("Two Once is %d\n",once);

	return NULL;
}

void *thread_fun2(void *arg)
{
	sleep(2);
	tid=pthread_self();
	printf("I`m thread 0x%x\n",tid);
	pthread_once(&once,thread_init);
	return NULL;
}

int main()
{
	pthread_t tid1,tid2;
	int err;
	
	err=pthread_create(&tid1,NULL,thread_fun1,NULL);
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
	
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);

	return 0;
}
