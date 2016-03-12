#include "stdio.h"
#include "unistd.h"
#include "fcntl.h"
int main(int argc,char *argv[] )
{
	int rd_fd,wr_fd;
	char buf[]="Hello world \n";
	char read_buf[128]={0};
	int wr_ret,rd_ret=128;
	
	if(argc<3)
	{
		printf("Please input src file and des file\n");
		return -1;
	}	

	rd_fd=open(argv[1],O_RDONLY);    //open src file
	if(rd_fd<0)
	{
		printf("Open file %s failure\n",argv[1]);
		return -2;
	}
	printf("Open file %s file success,\nthe rd_fd is %d\n ",argv[1],rd_fd);
	
	wr_fd=open(argv[2],O_WRONLY);	//open des src
	if (wr_fd<0)
	{	
		printf("Open file %s failure\n",argv[2]);
		return -3;
	}
	printf("Open file %s file success ,\n the wd_fd is %d\n ",argv[2],wr_fd);
	//when testing ,must build a des src,no by the program!
	while (rd_ret)
	{	
		rd_ret=read (rd_fd,read_buf,128);
		wr_ret=write(wr_fd,read_buf,rd_ret);
		printf("read_buf=%s\n",read_buf);
	}
	close (rd_fd);
	close(wr_fd);
	return 0;
}
