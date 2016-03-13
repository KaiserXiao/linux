#include "stdio.h"
#include "unistd.h"
#include "fcntl.h"
int main(int argc,char *argv[] )
{
	int fd;
	fd=open("./a.c",O_APPEND|O_RDWR);		//O_RDWR是可写可读，O_APPEND是追加
	if(fd<0)
	{
		printf("open file a.c failure\n");
		return -1;
	}
	printf("open  file a.c success ,the fd is %d ",fd);
	close (fd);
	return 0;
}
