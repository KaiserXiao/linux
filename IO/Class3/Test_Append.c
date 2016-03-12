#include "stdio.h"
#include "unistd.h"
#include "fcntl.h"
int main(int argc,char *argv[] )
{
	int fd;
	fd=open("./a.c",O_APPEND|O_RDWR);
	if(fd<0)
	{
		printf("open file a.c failure\n");
		return -1;
	}
	printf("open  file a.c success ,the fd is %d ",fd);
	close (fd);
	return 0;
}
