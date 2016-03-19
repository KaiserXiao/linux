#include "apue.h"
#define test 0
void sig_handler1(int arg)
{
	printf("One thread get signal\n");
	return ;
}


void sig_handler2(int arg)
{
	printf("Two thread get signal\n");
	return ;
}

void *thread_fun1(void *arg)
{
	printf("New thread One\n");
	
	struct sigaction act;
	memset(&act,0,sizeof(act));

	sigaddset(&act.sa_mask,SIGQUIT);
	act.sa_handler=sig_handler1;
	sigaction(SIGQUIT,&act,NULL);

	pthread_sigmask(SIG_BLOCK,&act.sa_mask,NULL);
	sleep(2);
	printf("fun One over\n");
}


void *thread_fun2(void *arg)
{
	printf("New thread Two\n");
	
	struct sigaction act;
	memset(&act,0,sizeof(act));

	sigaddset(&act.sa_mask,SIGQUIT);
	act.sa_handler=sig_handler2;
	sigaction(SIGQUIT,&act,NULL);

	//pthread_sigmask(SIG_BLOCK,&act.sa_mask,NULL);
	//对比thread_fun1，屏蔽掉mask，看看效果如何
	//先test置0，fun1先运行
	//发现打印出的是Two thread get signal
	//再test置1，变成了One thread get signal
	//哪个子线程最后运行，哪个子程序打印出来
	//这里的课程讲的很不清楚，估计是涉及到很多进程的知识
	sleep(2);
	
	printf("fun Two over\n");
}

int main()
{
	pthread_t tid1,tid2;
	int err;
	int s;

#if test
//这里的宏定义是为了修改fun1和fun2的执行顺序
//test为0时，fun1先执行
//test为1时，fun2先执行
err=pthread_create(&tid1,NULL,thread_fun1,NULL);
if(err)
{
	printf(" Fail to one create\n");
	return 0;
}

err=pthread_create(&tid2,NULL,thread_fun2,NULL);
if(err)
{
	printf(" Fail to one create\n");
	return 0;
}
#else
	err=pthread_create(&tid2,NULL,thread_fun2,NULL);
	if(err)
	{
		printf(" Fail to one create\n");
		return 0;
	}

	err=pthread_create(&tid1,NULL,thread_fun1,NULL);
	if(err)
	{
		printf(" Fail to one create\n");
		return 0;
	}
#endif

	printf("fist+++++");
	sleep(1);
	
	s=pthread_kill(tid1,SIGQUIT);
	if(s)
	{
		printf("Send signal to One Fail\n");
	}


	s=pthread_kill(tid2,SIGQUIT);
	if(s)
	{
		printf("Send signal to Two Fail\n");
	}
	
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	return 0;

	
}	

