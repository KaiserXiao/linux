#include "apue.h"

struct student{
	int id;
	int age;
	int name;
}stu;

//先定义两个全局变量
int i;
pthread_mutex_t mutex;

void *thread_fun1(void *arg)
{
	while(1)
	{
		pthread_mutex_lock(&mutex);
		stu.id=i;
		stu.age=i;
		stu.name=i;
		i++;
		if(stu.id!=stu.age || stu.id!=stu.name || 
		stu.age!=stu.name			)
		{
			printf("%d,%d,%d\n",stu.id,stu.age,stu.name);
			break;
		}
		pthread_mutex_unlock(&mutex);
	}
	return (void *)0;
}


void *thread_fun2(void *arg)
{
	while(1)
	{
		
		pthread_mutex_lock(&mutex);
		stu.id=i;
		stu.age=i;
		stu.name=i;
		i++;
		if(stu.id!=stu.age || stu.id!=stu.name || 
		stu.age!=stu.name			)
		{
			printf("%d,%d,%d\n",stu.id,stu.age,stu.name);
			break;
		}
		
		pthread_mutex_unlock(&mutex);
	}
	return (void *)0;
}

int main()
{
	pthread_t tid1,tid2;
	int err;
	//对互斥量进行初始化
	err=pthread_mutex_init(&mutex,NULL);
	if(err)
	{
		printf("init mutex fail\n");
		return 0;
	}
	err=pthread_create(&tid1,NULL,thread_fun1,NULL);
	if (err)
	{
		printf("Create ONE  thread failed\n");
		return 0;
	}

	
	err=pthread_create(&tid2,NULL,thread_fun2,NULL);
	if (err)
	{
		printf("Create TWO thread failed\n");
		return 0;
	}
	
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	
	return 0;
} 
