#include "stdio.h"
int main()
{
	int i=10;
	char buf[128]={0};
	sprintf(buf ,"i=%d",i);
	printf("buf is %s\n",buf);
	return 0;
}
