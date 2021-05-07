#include <stdio.h>
void tow(int(*b)[3],int i,int j)
{
	for(int a=0;a<i;a++)
		for(int c=0;c<j;c++)
			printf(" %d",b[a][c]);
}
void main()
{
	int a[2][3]={1,3,23,34,21,42};
	tow(a,2,3);
}
