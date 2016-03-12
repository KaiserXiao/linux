#include "stdio.h"
#include "unistd.h"
#include "fcntl.h"
int main(int argc,char *argv[] )
{
	int fd;
	char buf[]="Hello world \n";
	int wr_ret;	
	fd=open("./a.c",O_RDWR|O_TRUNC);    
	//There is same problem that also exist in Test_Trunc.c
	if(fd<0)
	{
		printf("Open file a.c failure\n");
		return -1;
	}
	printf("Open file a.c success ,the fd is %d ",fd);
	wr_ret=write(fd,buf,sizeof(buf));
	printf("wr_ret =%d\n",wr_ret);
	close (fd);
	return 0;
}
