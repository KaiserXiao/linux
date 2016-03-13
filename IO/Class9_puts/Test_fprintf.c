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
	fprintf(fp,"open  file a.c success ,the fd is %d\n ",fd);
	
	while(1);
	//ce shi hang huan cun `
	fclose (fp);
	return 0;
}
