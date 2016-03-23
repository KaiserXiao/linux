#include "apue.h"
#define  test 3
//全局变量
int num=0;

//读写锁
pthread_rwlock_t rwlock;

void *thread_fun1(void *arg)
{
	int err;
#if test==1
	pthread_rwlock_rdlock(&rwlock);		//test1
#elif test ==2
	pthread_rwlock_wrlock(&rwlock);		//test2
#else
 	pthread_rwlock_wrlock(&rwlock);		//test3
#endif
	printf("Thread One printf num %d\n",num);
	
	sleep(5);
	printf("One sleep over\n");
	
	pthread_rwlock_unlock(&rwlock);	
	
	return (void *)1;
}


void *thread_fun2(void *arg)
{
	int err;
#if test==1	
	pthread_rwlock_rdlock(&rwlock);		//test1	
#elif test==2
	pthread_rwlock_wrlock(&rwlock);		//test2
#else
	pthread_rwlock_rdlock(&rwlock);		//test3
#endif
	printf("Thread Two printf num %d\n",num);
	sleep(5);
	printf("Two sleep over\n");
	pthread_rwlock_unlock(&rwlock);	
	return (void *)1;
}

int main()
{
	pthread_t tid1,tid2;
	int err;
		
	err=pthread_rwlock_init (&rwlock,NULL);
	if(err)
	{
		printf("RwLock fail\n");
		return 0;
	}
	err=pthread_create(&tid1, NULL,thread_fun1,NULL);
	if(err)
	{
		printf("create new thread One Fail\n");
		return 0;
	}

	
	err=pthread_create(&tid2, NULL,thread_fun2,NULL);
	if(err)
	{
		printf("create new thread Two Fail\n");
		return 0;
	}

	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	
	pthread_rwlock_destroy(&rwlock);

	return 1;
}
