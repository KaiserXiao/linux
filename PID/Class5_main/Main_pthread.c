#include "apue.h"

struct student
{
	int age;
	char name[20];
};

void *thread_fun(void *stu)
{	
	sleep(2);
	//测试pthread_exit的功能
		
	return 0;
	printf("student name is %s.\nthe age is %d\n",
			((struct student*)stu)->name,
			((struct student*)stu)->age);
	//这里特别注意，强制类型转换
	//(struct student *)stu->name 这样是不行的
	//系统会先stu->name，再类型转换
	return (void *)0;
}

int main(int argc,char *argv[])
{
	pthread_t tid;
	int err;
	int i;
	int *rval;
	
	struct student str;
	str.age=20;
	//重点！！
	memcpy(str.name,"liSi",20);

	err=pthread_create(&tid,NULL,thread_fun,&str);
	if (err)
	{
		printf("Fail\n");
		return -1;
	}
	printf("Succes\n");
	
	for (i=0;i<argc;i++)
		printf("The thread argv is %s\n",argv[i]);
	
	//test 1
	//如果sleep(1)被注释掉，是没有name和age打印出来的
	//sleep(1);

	pthread_exit(rval);	
}
