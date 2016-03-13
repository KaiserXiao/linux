#include "stdio.h"
int main()
{
	//printf("Test1 printf ");		
	////test1		
	////直接与while(1)是没有打印出来的
	
	//fputs("Test2 fputs ",stdout);		
	////test2		////stdout
	////在stdout，输出到屏幕上，是没有的
	
	//fputs("Hello linux\n",stdout);	
	////test3		////stdout with "\n"
	////在stdout，加上\n，输出到屏幕上，没有问题
	
	
	fputs("Hello linux",stderr);		
	////test4		////stderr
	////在stderr上，是有输出的
	////意味着stdout是行缓存，而stderr是无缓存，直接输出
	
	
	while(1);
	return 0;
}
