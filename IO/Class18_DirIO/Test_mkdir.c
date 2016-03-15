#include "stdio.h"
#include "sys/types.h"
#include "dirent.h"

int main()
{
	int ret;
	DIR *dp;
	struct dirent *dir;	
	ret =mkdir("./mydir",0x777);  //like open ,umask
	if (ret<0)
	{
		printf("Fail!\n");
		return -1;
	}
	printf("create success! \n");

	dp=opendir("./mydir");
	if(dp==NULL)
	{
		printf("Open fail\n" );
		return -1;
	}
	printf("Open success\n");	

	dir=readdir(dp);
	while(dir)
	{
		printf("the dp is %ld \nino is %ld\nname is %s\n",\
		telldir(dp),dir->d_ino,dir->d_name);
		dir=readdir(dp);
	}
	closedir(dp);
	return 0;
	
}


