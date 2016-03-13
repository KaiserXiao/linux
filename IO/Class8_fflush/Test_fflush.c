////基于Class7的Test_fgets.c
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
	
	//Test fflush ,not cat argv[1]
	fflush(fp);	
	while(1);

	
	fclose(fp);
	return 0;
}

