//使用了 open,read ,write
//并不使用文件流
//使用系统调用函数 

#include "stdio.h"
#include "unistd.h"
#include "fcntl.h"
#include "string.h"
int main(int argc,char *argv[])
{
	int src_fd,des_fd;
	char Read_buf[128]={0};
	int  Read_ret;
	if(argc<3)
	{
		printf("Please input src file\n");
		return -2;
	}
	
	src_fd=open(argv[1],O_RDONLY);
	if(src_fd<0)
	{
		printf("Open src file %s failure\n",argv[1]);
		return -1;
	}
	printf("Open src file %s success\n",argv[1]);

	des_fd=open(argv[2],O_CREAT | O_WRONLY,0777);
	if(des_fd<0)
	{
		printf("Open des file %s failure\n",argv[2]);
		return -1;
	}
	printf("Open des file %s success\n",argv[2]);

	while(1)
	{
		Read_ret=read(src_fd,Read_buf,128);
		write(des_fd,Read_buf,Read_ret);
		if(Read_ret<128)
		{
			printf("read file %s end\n",argv[1]);
			break;
		}
	}
	
	printf("\n+++++++++++++++finish++++++++++++++++\n");
	close(src_fd);
	close(des_fd);	
	return 1;
}	
