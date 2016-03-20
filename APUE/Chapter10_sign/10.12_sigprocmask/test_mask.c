#include "apue.h"
#include <errno.h>

void pr_mask(const char *str)
{
	sigset_t sigset;
	int errno_save;
	
	errno_save=errno;
	if(sigprocmask(0,NULL,&sigset)<0)
	{
		err_set("sigprocmask error");
	}
	else
	{
		printf("%s",str);
		if(sigismember(&sigset,SIGINT))
			printf("SIGINT\n");
		if(sigismember(&sigset,SIGQUIT))
			printf("SIGQUIT\n");
		if(sigismember(&sigset,SIGUSR1))
			printf("SIGUSR1\n");
		if(sigismember(&sigset,SIGALRM))	
			printf("SIGALRM\n");

	}
	errno=errno_save;
	
}

void main()
{
//抱歉，不知道怎么测试
}
