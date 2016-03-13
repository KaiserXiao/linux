#include "stdio.h"
#include "string.h"
int main()
{
	char buf[128]={0};
	//gets(buf);
	//printf("The length of buf is %d\n",strlen(buf));
	////test 1
	////dont accept "\n"
	
	fgets(buf,128,stdin);
	printf("The length of buf is %d\n",strlen(buf));
	////test 2
	////accept "\n"

	puts(buf);
	////test 3
	////add "\n"

	
	//fputs(buf,stdout);
	
	return 0;	
}
