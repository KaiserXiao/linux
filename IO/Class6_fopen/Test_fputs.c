#include "stdio.h"
int main(int argc,char *argv[])
{
	FILE *fp;
	char Wr_buf[]="Hello linux";
	char Rd_buf[128];
	fp=fopen(argv[1],"w+");
	//fp=fopen(argv[1],"a+");
	if(NULL==fp)
	{
		printf("open file %s failure.\n",argv[1]);
		return -1;
	}
	printf("Open file %s success.\n",argv[1]);
	fputs(Wr_buf,fp);
	
	//fgets(Rd_buf,128,fp);
	//printf("The Rd_buf is %s\n",Rd_buf);	
	
	//while(1);			
	////如果fgets和while都被激活和while都被激活
	////那么在整个程序暂停后shell可以看到还是有显示
	////fputs可能使用了刷新内存的函数fflush
	
	fclose(fp);
	return 0;
}

