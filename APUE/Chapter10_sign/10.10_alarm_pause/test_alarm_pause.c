#include <signal.h>
#include <unistd.h>
#include <stdio.h>


static void sig_alrm(int signo)
{
	;
}

unsigned int sleep1(unsigned int seconds)
{
	if(signal(SIGALRM,sig_alrm)==SIG_ERR)
		return seconds;
	printf("Alarm Begin\n");
	alarm(seconds);
	printf("Pause Begin\n");
	pause();
	return (alarm(0));
}

int main()
{	
	unsigned int seconds=2;
	printf("Begin!\n");
	sleep1(seconds);
	printf("Over!\n");
	return 0;
}
