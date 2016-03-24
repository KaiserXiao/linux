#include "apue.h"

int main()
{
	char *shm1="myshm";
	char *shm2="youshm";

	int shm_id_1,shm_id_2;
	
	char *buf;
	pid_t pid;

#if 1
	pthread_mutex_t *mutex;
	pthread_mutexattr_t mutexattr;
	
 	shm_id_2=shm_open(shm2,O_RDWR|O_CREAT,0644);
	
	ftruncate(shm_id_2,100);
	
	mutex=(pthread_mutex_t*)mmap(NULL,100,PROT_READ|PROT_WRITE,MAP_SHARED,shm_id_2,0);
	
	pthread_mutexattr_init(&mutexattr);
//不要检查属性
#ifdef _POSIX_THREAD_PROCESS_SHARED
	//pthread_mutexattr_setpshared(&mutexattr,PTHREAD_PROCESS_SHARED);
	pthread_mutexattr_setpshared(&mutexattr,PTHREAD_PROCESS_PRIVATE);
#endif
	pthread_mutex_init(mutex,&mutexattr);
#endif


	//打开共享内存
 	shm_id_1=shm_open(shm1,O_RDWR|O_CREAT,0644);
	
	//调整共享内存大小
	ftruncate(shm_id_1,100);
	
	//映射共享内存，MAP_SHARED属性表明，对共享内存的任何修改都会影响到其他进程
	buf=(char*)mmap(NULL,100,PROT_READ|PROT_WRITE,MAP_SHARED,shm_id_1,0);
	
	//创建新进程
	pid=fork();
	if(pid==0) 
	{
		//休眠1秒，让父进程先运行
		sleep(1);
		printf("I`m child process\n");

		//修改数据时锁上
		pthread_mutex_lock(mutex);
		
		//讲共享内存修改为hello
		memcpy(buf,"hello",6);
		printf("Child buf is %s\n",buf);
		//修改好数据解锁
		pthread_mutex_unlock(mutex);
	}
	else if (pid>0)
	{
		printf("I`m parent process\n");
		//修改数据时锁上	
		pthread_mutex_lock(mutex);
		//修改共享内存到内容，改为world
		memcpy(buf,"world",6);
		
		//休眠3秒，让子进程运行
		sleep(3);

		//修改好数据后解锁	
		pthread_mutex_unlock(mutex);
		printf("parent buf is :%s\n",buf);
	}
	//解除属性和互斥量
	pthread_mutexattr_destroy(&mutexattr);
	pthread_mutex_destroy(mutex);	

	//解除buf内存
	munmap(buf,100);

	//解除mutex内存
	munmap(mutex,100);

	//解除共享内容
	shm_unlink(shm1);

	//解除共享内容
	shm_unlink(shm2);

	return 0;
}
