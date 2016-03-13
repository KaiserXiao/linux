#include "stdio.h"
#include "string.h"
int main()
{
	char buf[128]={0};
	//gets(buf);
	////gets函数从键盘直接读字符
	////按下回车结束，所以不会包含"\n"
	
	fgets(buf,128,stdin);
	////可以从其他文件读，会包含 "\n"
	
	printf ("len is %d\n",strlen(buf));	
	
	//fputs(buf ,stdout);
	////fputs函数不会添加"\n"

	puts(buf);
	////puts 函数会在结尾添加"\n"
	return 0;
}
