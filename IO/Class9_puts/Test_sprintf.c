#include"stdio.h"
int main()
{
	int i=10;
	char buf[128]={0};
	sprintf(buf,"i=%d",i);
	////注意sprintf的用法，对buf进行操作
	printf("buf is %s\n",buf );
	return 0;
}
