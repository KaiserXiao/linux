#include "stdio.h"
#include "unistd.h"
#include "fcntl.h"
int main(int argc,char *argv[] )
{
	FILE *fp;	
	int fd=10;
	fp=fopen("./a.c","w+");	
	if(fp==NULL)
	{
		printf("open file a.c failure\n");
		return -1;
	}
	fprintf(fp,"Open a.c success the fd is %d",fd);
	////test1
	
	while(1);
	////test2
	////ce shi .. . hang hun cun

	fclose (fp);
	return 0;
}
