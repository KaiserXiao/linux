#include "apue.h"

void print_id(char *s)
{
	pid_t pid;
	pthread_t tid;
	
	pid=getpid();
	tid=pthread_self();
	
	printf("%s pid is %u\n,tid is %x\n",s,pid,tid);

}

void *thread_fun(void *arg)
{
	print_id(arg);
	return (void*)0;
}

int main()
{
	pthread_t new_tid;
	int err;
	
	err = pthread_create(&new_tid,NULL,thread_fun,"New pthread :");
	if (err!=0)
	{
		printf("Fail\n");
		return -1;
	}

	print_id("The main thread is :");
	sleep(2);
 
	return 0;
}

