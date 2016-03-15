#include "stdio.h"
#include "sys/types.h"
#include "dirent.h"
#include "string.h"
#include "unistd.h"
#include "fcntl.h"

int main(int argc,char *argv[])
{
	DIR *dp=NULL;
	int fp;
	struct dirent *dir;
	int src_fd,des_fd;
	char target_dir[128]={0};	
	char target_file[128]={0};
	char Read_buf[128];
	int Num_rd=128;
	while(!dp)
	{
		printf("Please input dirent`s name \n");
		scanf("%s",target_dir);
	
		//List Target
		dp=opendir(target_dir);
		if (!dp)
			printf("Can`t find the target\n");
	}
	


	//read the dirent	
	dir=readdir(dp);
	while(dir)
	{
		printf("The ino is %ld\nThe file`s name is %s\n",\
			dir->d_ino,dir->d_name);	
		dir=readdir(dp);
	}
	

	
	//sure the file we need
	src_fd=-1;
	while(src_fd<0)
	{
		printf("Please input fiile`s name \n");
		scanf("%s",target_file);
		src_fd=open(strcat(strcat(target_dir,"/"),target_file),O_RDONLY);
		if (src_fd<0)
			printf("Can`t find the target\n");
	}

	//copy
	des_fd=open( target_file ,O_CREAT | O_WRONLY , 0777 );
	if (des_fd<0)
		return -1;
	
	while(Num_rd==128)
	{
		Num_rd=read(src_fd, Read_buf,128);
		write(des_fd,Read_buf,Num_rd);
	}
	close(des_fd);
	close(src_fd);	
	closedir(dp);
}	
