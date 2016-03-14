#include "stdio.h"
#include "string.h"
int main(int argc,char *argv[])
{
	FILE *src_fp;
	char Write_buf[128]="Hello linux\n";
	char Read_buf[128];
	if(argc<2)
	{
		printf("Please input src file\n");
		return -2;
	}
	
	src_fp=fopen(argv[1],"w+");
	if(src_fp<0)
	{
		printf("Open src file %s failure\n",argv[1]);
		return -1;
	}
	printf("Open src file %s success\n",argv[1]);
	fwrite(Write_buf,sizeof(char),sizeof(Write_buf),src_fp);
	//	while(1);
	////test 1
	////测试是否为"\n"行缓存
	////结果不是，没有显示出来

	//fflush(src_fp);
	////test 2
	////强制刷新，有缓存但不是行缓存	

	////start read
	rewind(src_fp);
	fread(Read_buf,sizeof(char),sizeof(Write_buf),src_fp);
	////test 3
	////没有fflush，依旧有显示，猜测fread里面有fflush
	printf("the Read_buf is %s\n",Read_buf);
	fclose(src_fp);	
}	
