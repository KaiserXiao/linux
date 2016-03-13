//基于Class7

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
	
	//fseek(fp,0,SEEK_SET);	//test1	//fseek..
	//rewind(fp);		//test2 
	
	//printf("The ftell(fp) retrun %ld \n ",ftell(fp));	
	//test3	
	
	printf("The ftell(fp)1 retrun %ld \n ",ftell(fp));	
	rewind(fp);
	printf("The ftell(fp)2 retrun %ld \n ",ftell(fp));	
	//test4
	//这里有必要解释一下，rewind会把fp的值打出来
	//test4可以看出ftell和rewind的作用
	
	fgets(Rd_buf,128,fp);
	//没有rewind和fseek，fgets的Rd_buf是乱码
	printf("The Rd_buf is %s\n",Rd_buf);	
	fclose(fp);
	return 0;
} 
