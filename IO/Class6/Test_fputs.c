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
	//"fputs" make the point "fp" changed! 
	//printf("The Rd_buf is %s\n",Rd_buf);	
	
	//while(1);
	//if line18 is comment ,the while(1) will success,
	//I guess fgets have some action to memory
	fclose(fp);
	return 0;
}

