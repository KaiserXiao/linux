#include "apue.h"

void *thread_fun(void *arg)
{
	if (strcmp("1",(char *)arg)==0)
	{
		printf("Now pthread return !\n");
		return ( void *)1;
	}


	if (strcmp("2",(char *)arg)==0)
	{
		printf("Now pthread_exit !\n");
		pthread_exit((void*)2);
	}


	if (strcmp("3",(char *)arg)==0)
	{
		printf("Now thread exit !\n");
		exit(3) ;
	}
}

int main (int argc,char *argv[])
{
	int err;
	pthread_t tid;

	err=pthread_create(&tid,NULL,thread_fun,(void *)argv[1]);
	
	if(err)
	{
		printf ("Create new thread fail\n");
		return 0;
	}

	sleep(1);
	printf("main thread\n");
	return 0;
}

