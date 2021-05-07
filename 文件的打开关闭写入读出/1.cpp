#include <stdio.h>
 
void main()
{
	FILE * fp;
	fp=fopen("D:\\a.txt","a+");
	if(fp==NULL)
		printf("´íÎó£¡\n");
	char ch,ch1;
	ch=getc(fp);
	ch1=getchar();
	putchar(ch1);
	while(ch1!='#')
	{
		fputc(ch1,fp);
		ch1=getchar();
	}
	fclose(fp);
}