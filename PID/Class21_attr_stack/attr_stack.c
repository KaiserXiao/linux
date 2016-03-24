#include "apue.h"
pthread_t tid;

//定义属性变量
pthread_attr_t attr;

void *thread_fun1(void *arg)
{
	size_t stacksize;
	printf("I`m thread 0x%x\n",pthread_self());

#ifdef _POSIX_THREAD_ATTR_STACKSIZE
	pthread_attr_getstacksize(&attr,&stacksize);
	printf("First thread stack size is %d\n",stacksize);
	pthread_attr_setstacksize(&attr,20000);
	pthread_attr_getstacksize(&attr,&stacksize);
	printf("Second thread stack size is %d\n",stacksize);
#endif

	return  (void*)1;
}


int main()
{
	pthread_t tid1,tid2;
	int err;
	

	//初始化
	pthread_attr_init (&attr);

	//改为可连接	
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_JOINABLE);

#ifdef _POSIX_THREAD_ATTR_STACKSIZE
//	pthread_attr_setstacksize(&attr,PTHREAD_STACK_MIN);
#endif
	err=pthread_create(&tid1,&attr,thread_fun1,NULL);
	if(err)
	{
		printf("Create Fail\n");
		return 0;
	}


	err=pthread_create(&tid1,NULL,thread_fun1,NULL);
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
