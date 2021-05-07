#include<stdio.h>
int main()
{
	char* x[3];
	x[0]="I";
	x[1]="LOVE";
	x[2]="CHINA";
	for(int i=0;i<3;i++)
		printf("%s",x[i]);
	return 0;
}