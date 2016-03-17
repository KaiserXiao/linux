#include "apue.h"
#define test 0
//第30行将对整个test做出解释
void *thread_fun(void *arg)
{
#if test 
	sleep(1);
#endif
	printf("I`m  thread_fun\n");
	return (void *)0;

}

int main()
{
	pthread_t tid;
	int err;
	int s;
	void *rval;


	err=pthread_create(&tid,NULL,thread_fun,NULL);
	if (err)
	{
		printf("Create new thread Fail\n");
		return 0;
	}
	printf("Create success\n");
#if test
	s=pthread_kill(tid,SIGQUIT);
	//一开始test置0，会看到线程的消失，但主线程依旧存在
	//再置1，可以看到
	//这里没有对SIGQUIT做任何处理
	//所以会退主线程（Main）
	//连同后面的printf("Main pthread\n");也没打印出来
	//在本系统中，直接是显示QUIT(CORE DUMP)
	
#else 
	sleep(1);
	s=pthread_kill(tid,0);
#endif
	

	if( s ==  ESRCH )
		printf("thread tid is not found\n");
#if 1
	pthread_join(tid,&rval);
#endif

	printf("Main pthread\n");
	return 0;
}

