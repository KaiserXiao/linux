//安全使用fork

#include "apue.h"
//注意，这里的mutex和之前的不一样
//之前的定义为 pthread_mutex_t *mutex
//之前是指针，pthread_mutex_lock之类的没有&
//现在是变量，要加上&，变成地址
pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;
#if 1
void prepare()
{
	pthread_mutex_lock(&mutex);
	printf("Prepare\n");
}

void parent()
{
	pthread_mutex_unlock(&mutex);
	printf("PARENT\n");
}

void child()
{
	pthread_mutex_unlock(&mutex);
	printf("CHILD\n");
}

#endif
void *thread_fun(void *arg)
{
	sleep(1);
	pid_t pid;

//prepare是在fork之前调用，获取互斥量
//parent是在fork返回父进程之前调用，负责解锁？
//child也是在fork返回子进程之前，负责解锁
#if 1
	pthread_atfork(prepare,parent,child);
#endif
	pid=fork();
	if(!pid)
	{	
		pthread_mutex_lock(&mutex);
		printf("Child\n");
		pthread_mutex_unlock(&mutex);
	}
	if(pid>0)
	{
		pthread_mutex_lock(&mutex);
		printf("Parent\n");
		pthread_mutex_unlock(&mutex);
	}
}


int main()
{
	pthread_t tid;

	if(pthread_create(&tid,NULL,thread_fun,NULL))
	{
		printf("create new thread failed\n");
		return 0;
	}

	
	pthread_mutex_lock(&mutex);
	sleep(2);
	pthread_mutex_unlock(&mutex);

	printf("Main\n");
	pthread_mutex_destroy(&mutex);

	pthread_join(tid,NULL);
	return 1;
}

