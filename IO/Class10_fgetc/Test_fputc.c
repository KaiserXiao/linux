////ji yu class7
#include "stdio.h"
int main(int argc,char *argv[])
{
	FILE *fp;
	fp=fopen(argv[1],"w+");
	if(NULL==fp)
	{
		printf("open file %s failure.\n",argv[1]);
		return -1;
	}
	printf("Open file %s success.\n",argv[1]);
	fputc('a',fp);
	////test 1

	fputc('\n',fp);
	////test 2

	fflush(fp);
	while(1);	
	
	
	fclose(fp);
	return 0;
}

