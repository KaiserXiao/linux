////ji yu class7
#include "stdio.h"
int main(int argc,char *argv[])
{
	FILE *fp;
	char ret;
	fp=fopen(argv[1],"w+");
	if(NULL==fp)
	{
		printf("open file %s failure.\n",argv[1]);
		return -1;
	}
	printf("Open file %s success.\n",argv[1]);
	fputc('a',fp);

	rewind (fp);	
	ret=fgetc(fp);
	printf("ret is %c\n",ret);	
	
	ret=fgetc(fp);	
	printf("ret is %d\n",ret);	
	////EOF	   注意这里用的%d
	
	printf("feof is %d\n ferror is %d\n",feof(fp),ferror(fp));	
	clearerr(fp);	
	
	printf("feof is %d\n ferror is %d\n",feof(fp),ferror(fp));	
	fclose(fp);
	return 0;
}

