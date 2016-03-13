#include "stdio.h"
#include "string.h"
int main()
{
	char buf[128]={0};
	//gets(buf);
	////no include"\n" 	
	
	fgets(buf,128,stdin);
	////include "\n"
	
	printf ("len is %d\n",strlen(buf));	
	
	//fputs(buf ,stdout);
	////no add "\n"

	puts(buf);
	////add "\n"
	return 0;
}
