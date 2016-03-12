#include "stdio.h"
int main(int argc,char *argv[])
{
	FILE *fp;
//	fp=fopen(argv[1],"w+");
	fp=fopen(argv[1],"a+");
	if(NULL==fp)
	{
		printf("create file %s failure.\n",argv[1]);
		return -1;
	}
	printf("Create file %s success.\n",argv[1]);
	fclose(fp);
	return 0;
}

