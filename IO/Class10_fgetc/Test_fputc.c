////基于Class7
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
	////test 3
	while(1);	
	////测试fputc是否为行缓存，结果不是
	////但又明确使用了缓存
	fclose(fp);
	return 0;
}

