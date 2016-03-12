#include "stdio.h"
#include "unistd.h"
#include "fcntl.h"
int main(int argc,char *argv[] )
{
	int fd;
	fd=open("./a.c",O_CREAT|O_EXCL|O_RDWR,0x777);
	if(fd<0)
	{
		printf("Create  file a.c failure\n");
		return -1;
	}
	printf("Create file a.c success ,the fd is %d ",fd);
	close (fd);
	return 0;
}
