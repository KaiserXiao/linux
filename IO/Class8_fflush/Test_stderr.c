#include "stdio.h"
int main()
{
	//printf("Test1 printf ");		//test1		
	
	//fputs("Test2 fputs ",stdout);		//test2		//stdout
	
	//fputs("Hello linux\n",stdout);	//test3		//stdout with "\n"
	
	fputs("Hello linux",stderr);		//test4		//stderr
	//cant no see Hello linux
	while(1);
	return 0;
}
