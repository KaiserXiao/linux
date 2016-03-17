#include "apue.h"

void *thread_fun(void *arg)
{
	int stateval;
	int type_val;	


	stateval =pthread_setcancelstate(PTHREAD_CANCEL_DISABLE,NULL);
	if (stateval)
		printf ("Set cancel disalbe fail");
	printf("I`m new state\n");
	printf("Now ,sleep 4 seconds\n");
	sleep(4);
	
	printf("about to cance\n");
#if 1
	stateval= pthread_setcancelstate(PTHREAD_CANCEL_ENABLE,NULL);
#else
	stateval= pthread_setcancelstate(PTHREAD_CANCEL_DISABLE,NULL);
#endif
	if (stateval)
		printf("Set cancel enable fail");

	
	type_val=pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS,NULL);
	if (type_val)
		printf("Set tpye value fail\n");
	printf("Set tpye value success\n");
	//设为及时响应模式，而不是延时响应模式
	//看看下面的两个语句有没有打印出来

	printf("first cancel point\n");
	//这里加第二个取消点，测试在延时取消（默认），是怎么运行的
	//很明显在DISABLE 的情况下，无论有多少个取消点（printf）
	//线程都继续运行着，没有被取消
	//而一旦ENABLE后，仅仅打印了上面的语句。而没有了下面的语句
	//test :将ENABLE改为DISABLE试试，看看最后的exit code 是不是变成这个函数的返回值20？
	printf("second cancel point \n");
	
	return  (void *)20;
}

int main()
{
	pthread_t tid;
	int  err ,cval,jval;
	void *rval;

	err=pthread_create(&tid,NULL,thread_fun,NULL);
	if (err)
	{
		printf("Create thread fail\n");
		return 0;
	}
	
	printf("Create thread success\n");
	printf("Now sleep 2 seconds\n");
	sleep(2);
	//当开始sleep后，调度开始，系统会运行已经创建好的了pthread_fun
	//故后面的sleep over要在pthread_fun中的slepp(4)开始后才能看到
	printf("sleep 2 seconds over\n");

	cval=pthread_cancel(tid);
	if(cval)
		printf("cancel thread  failed in Main\n");
	printf("cancel thread success in Main\n");
	

	printf("50-Join fun work\n");
	jval=pthread_join(tid,&rval);
	//上面的join后没有马上打印下面的code，而是继续运行了上面sleep(4)后的第11行的代码
	printf("New thread exit code is %d \n",(int *)rval);
		
	return 0;
}
