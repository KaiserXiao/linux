#include "apue.h"
#define test 0
void sig_handler1(int arg)
{
	printf("One thread get signal\n");
	return ;
}

void sig_handler3(int arg)
{
	printf("THREE thread get signal\n");
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
	
	//sruct sigaction
	//{
	//	void(*sa_handler)(int);	
	//	void(*sa_sigaction)(int ,siginfo *,void *)
	//	sigset_t sa_mask;
	//	int sa_flags;
	//	void(*sa_restorer)(void);
	//}
	//LinuxSystemProgramming P334
		
	struct sigaction act;

	//首先对结构体act清零
	memset(&act,0,sizeof(act));
	//对掩码进行处理
	sigaddset(&act.sa_mask,SIGQUIT);
	//初始化sa_handler
	act.sa_handler=sig_handler1;
	
	//SIG_SETMASK，中断屏蔽掉act.sa_mask信号
	pthread_sigmask(SIG_SETMASK,&act.sa_mask,NULL); 
	
	sigaction(SIGQUIT,&act,NULL);
#if 0
	for (;;)
		pause();
#else
	sleep(2);
#endif
	printf("fun One over\n");
	return ;
}


void *thread_fun3(void *arg)
{
	printf("New thread THREE\n");
	
		
	struct sigaction act;

	//首先对结构体act清零
	memset(&act,0,sizeof(act));
	//对掩码进行处理
	sigaddset(&act.sa_mask,SIGQUIT);
	//初始化sa_handler
	act.sa_handler=sig_handler3;
	
	sigaction(SIGQUIT,&act,NULL);
	//pthread_sigmask(SIG_BLOCK,&act.sa_mask,NULL);
	sleep(2);
	printf("fun THREE over\n");
	return ;
}

void *thread_fun2(void *arg)
{
	printf("New thread Two\n");
	struct sigaction act;
	
	memset(&act,0,sizeof(act));

	sigaddset(&act.sa_mask,SIGQUIT);
	act.sa_handler=sig_handler2;
	sigaction(SIGQUIT,&act,NULL);

	pthread_sigmask(SIG_BLOCK,&act.sa_mask,NULL);
	//pthread_sigmask(SIG_UNBLOCK,&act.sa_mask,NULL);
	//对比thread_fun1，屏蔽掉mask，看看效果如何
	//先test置0，fun1先运行
	//发现打印出的是Two thread get signal
	//再test置1，变成了One thread get signal
	//哪个子线程最后运行，哪个子程序打印出来
	//也就是说首先运行的那个程序被SIGQUIT了
	sleep(2);
	
	printf("fun Two over\n");
	return ;
}


int main()
{
	pthread_t tid1,tid2,tid3;
	int err;
	int s;

#if test
//这里的宏定义是为了修改fun1和fun2的执行顺序
//test为0时，fun2比fun1先create，fun1先执行
//test为1时，fun1比fun2先create，fun2先执行


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


	err=pthread_create(&tid3,NULL,thread_fun3,NULL);
	if(err)
	{
		printf(" Fail to THREE create\n");
		return 0;
	}
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
	
	printf("fist+++++\n");
	sleep(1);

 	printf("Begin to kill one\n");
	for(;;)
	{
		pause();
		getchar();
		pthread_kill(tid1,SIGQUIT);
	}
	return 0;
}	

