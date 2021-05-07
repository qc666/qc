#include <stdio.h>
#include <string.h>
int main()
{
	char str[2][30],string[40]={"china"};
	int i=0;
	for(i=0;i<2;i++)
		gets(str[i]);
	for(i=0;i<2;i++)
		printf("%d ",strlen(str[i]));
	printf("\n");
	strcat(str[0],str[1]);
	printf("%s",str[0]);
	printf("\n");
	strcpy(string,str[0]);
	printf("%s",string);
	printf("\n");
	printf("%d",strcmp(str[0],str[1]));
	printf("\n");
	printf("%s",strupr(string));
	printf("\n");
	printf("%s",strlwr(string));
	printf("\n");
	return 0;
}
