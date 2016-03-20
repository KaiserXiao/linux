#include "apue.h"

static void sig_quit(int);

int main(void)
{
	sigset_t newmask,oldmask,pendmask;
	
	if(signal(SIGQUIT,sig_quit)==SIG_ERR)
		printf("Can not catch SIGQUIT\n");

	//清空信号集	
	sigemptyset(&newmask);
	
	//开启SIGQUIT信号集
	sigaddset(&newmask,SIGQUIT);
	
	//使newmask的信号集起作用，BLOCK为关中断，阻塞接受不了该信号
	//当前屏蔽字给oldmask，作为本源保存，要退出时setmask还原
	//新的屏蔽字给newmask，可以拿去多次处理
	if(sigprocmask(SIG_BLOCK,&newmask,&oldmask)<0)
		printf("SIG_BLOCK error\n");

	
	printf("first sigprocmask over\n");
	//用上面的printf语句判断在sigprocmask返回前，
	//SIG_QUIT是否会传给Main
	//很明显不会，上面一行的printf先打印，再打印出sig_quit的语句
	//直到sleep开启调度，signal开始响应中断信号
	//但退出的中断信号被程序所屏蔽
	//没有退出
	sleep(5);
	
	//sigpending函数返回在送往进程的时候被阻塞挂起的信号集合	
	if (sigpending(&pendmask)<0)
		printf("sigpending error\n");

	//sigismemeber询问被阻塞信号中是否有某个成员
	if(sigismember(&pendmask,SIGQUIT))
		printf("\nSIGQUIT pending\n");
	//上面两句话
	//首先把当下进程被阻塞的信号送到pendmask，然后检查里面有没有SIGQUIT

	//SETMASK为重新设置中断，用oldmask即之前的屏蔽字来重设
	//当前屏蔽字给NULL，不必保留
	if(sigprocmask(SIG_SETMASK,&oldmask,NULL)<0)
		printf("SIG_SETMASK errpr\n");
	printf("SIGQUIT unblocked\n");

	sleep(5);
	exit(0);
}

static void sig_quit(int signo)
{
	printf("Caught SIGQUIT\n");
	if (signal(SIGQUIT,SIG_DFL)==SIG_ERR)
		printf("Can not reset SIGQUIT\n");
}

	
