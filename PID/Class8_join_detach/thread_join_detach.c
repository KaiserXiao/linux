#include "apue.h"

void *thread_fun1 (void *arg)
{
	printf("Thread one\n");
	return (void*)1;
}


void *thread_fun2 (void *arg)
{
	printf("Thread two\n");
	//pthread_detach (pthread_self());
	//detach分离线程，self自身线程数
	//fun2分离了它自己
	pthread_exit( (void*)2);
	//return 和 pthread_exit 都不会使主线程，进程退出
}

int main()
{
	int err1,err2;
	pthread_t tid1,tid2;
	void *rval1,*rval2;

	err1=pthread_create(&tid1,NULL,thread_fun1,NULL);
	err2=pthread_create(&tid2,NULL,thread_fun2,NULL);
	
	if(err1||err2)
	{
		printf("Create new pthread failed\n");
		return 0;
	}
	
	printf("Main Pthread\n");
	printf("Join rval one is %d\n",pthread_join(tid1,&rval1));
	//join是线程连接，把线程连接到本线程
	//这里的意思是要将fun1执行？
	//而且前面程序的sleep也没了
	//没有发生调度？
	printf("Join rval two is %d\n",pthread_join(tid2,&rval2));
	//当detach打开时，会返回22
	//在/usr/include/asm-generic/errno-base.h中可以看到
	//err22就是EINVAL
	//然后在man pthread_join 中return value 中看到它的意思


	printf("one exit code is %d\n",(int*)rval1 );
	printf("two exit code is %d\n",(int*)rval2 );

//	sleep(2);	printf("sleep over\n");
	printf("Main over!\n" );
	return 0;
}


