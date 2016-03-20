#include "apue.h"

static void sig_usr(int);


	//signal函数详解：
	//signal()用于确定以后当信号sig出现时的处理方法。
	//如果handler的值是SIG_DFL，那么就采用实现定义的缺省行为；
	//如果handler的值是SIG_IGN，那么就忽略该信号；
	//否则，调用handler所指向的函数(参数为信号类型)。
	//signal()返回信号sig原来的的handler；
	//如果出错，则返回SIG_ERR。
	//当随后出现信号sig时，
	//就中断正在执行的操作，转而执行信号处理函数(*handler)(sig)。
	//如果从信号处理程序中返回，则从中断的位置继续执行。


int main(void)
{
	if(signal(SIGUSR1,sig_usr)==SIG_ERR)
		printf("Can not find SIGUSR1");
	if (signal(SIGUSR2,sig_usr)==SIG_ERR)
		printf("Can not find SIGUSR2");
	
	
	//if (signal(SIGINT,sig_usr)==SIG_ERR)
	//	printf("Can not find SIGINT");
	////test1:输入-INT，就会打印Received signal is 2

	//if(signal(SIGINT,SIG_IGN)!=SIG_IGN)
	//	signal(SIGINT,sig_usr);
	////test2:
	////直接./test_signal
	////按下ctrl+c，发现打印Received signal is 2
	
	////SIGINT=2?
	
	signal(SIGINT,sig_usr);
	////test3:删掉if判断，看看会有什么效果
	////好像没什么影响，估计是前后台的概念问题
	for (;;)
		pause();
}

	//在shell中输入./test_signal &
	//kill -USR1 进程号
	//kill -USR2 进程号
	//会发现出现下面的Received语句_

static void sig_usr(int signo)
{
	if(signo==SIGUSR1)
		printf("Received SIGUSR1\n");
	else if (signo==SIGUSR2)
		printf("Received SIGUSR2\n");
	else
		printf("Received signal is %d\n",signo);
}

