#include<stdio.h>
void huhuan(int * p,int * q)
{
	int t;
	t=*q;
	*q=*p;
	*p=t;
}
int main()
{
	int a=3,b=5;
	huhuan(&a,&b);
	printf("a=%d,b=%d\n",a,b);
	return 0;
}
