#include <stdio.h>
void f(int* p,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",*(p+i));
		printf("%d ",p[i]);		
		printf("%d ",p+i);
		printf("\n");
	}
}
int main()
{
	int a[]={22,33,34,23,54,65,28};
	f(a,sizeof(a)/sizeof(a[0]));
	printf("%d \n",sizeof(a)/sizeof(a[0]));
	return 0;
}
