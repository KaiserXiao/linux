#include "apue.h"

int main()
{
	pid_t pid;
	pthread_t tid;

	pid=getpid();
	tid=pthread_self();
	printf("pid is %u\ntid is %x \n",pid,tid);
	return 0;
}
