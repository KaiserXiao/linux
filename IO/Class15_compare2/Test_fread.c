#include "stdio.h"
#include "unistd.h"
#include "fcntl.h"
#include "string.h"
int main(int argc,char *argv[])
{
	FILE *src_fp,*des_fp;
	char Read_buf[128];
	int Read_ret;
	if(argc<3)
	{
		printf("Please input src file\n");
		return -2;
	}
	
	src_fp=fopen(argv[1],"r");
	if(src_fp<0)
	{
		printf("Open src file %s failure\n",argv[1]);
		return -1;
	}
	printf("Open src file %s success\n",argv[1]);
	
	des_fp=fopen(argv[2],"w+");
	if(des_fp<0)
	{
		printf("Open des file %s failure\n",argv[2]);
		return -1;
	}
	printf("Open des file %s success\n",argv[2]);
#if 0
	while((Read_ret=fgetc(src_fp))&&!feof(src_fp))
		fputc(Read_ret,des_fp);
	////feof return 1 if end
#else	
	Read_ret=sizeof(Read_buf);
	while(Read_ret==sizeof(Read_buf))
	{
		Read_ret=fread(Read_buf,sizeof(char),sizeof(Read_buf),src_fp);
		fwrite(Read_buf,sizeof(char),Read_ret,des_fp);
	}
#endif
	printf("finish\n");
	fclose(src_fp);	
	fclose(des_fp);
}	
