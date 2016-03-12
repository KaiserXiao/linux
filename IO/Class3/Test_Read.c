#include "stdio.h"
#include "unistd.h"
#include "fcntl.h"
int main(int argc,char *argv[] )
{
	int fd;
	char buf[]="Hello world \n";
	char read_buf[128]={0};
	int wr_ret,rd_ret;	
	fd=open("./a.c",O_RDWR|O_TRUNC);    
	//There is same problem in Test_Trunc.c
	if(fd<0)
	{
		printf("Open file a.c failure\n");
		return -1;
	}
	printf("Open file a.c success ,the fd is %d ",fd);
	wr_ret=write(fd,buf,sizeof(buf));
	printf("wr_ret =%d\n",wr_ret);
	
	//start read
	read (fd,read_buf,128);
	//The problem is in the fd,the fd is changed by the write!
	printf("read_buf=%s\n ",read_buf);

	close (fd);
	return 0;
}
