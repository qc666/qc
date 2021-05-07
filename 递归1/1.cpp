#include <stdio.h>
int a(int n)
{
	if(n==1)
		return 1;
	else 
		return (a(n-1)+n);
}
int main()
{
	int max;
	max=a(100);
	printf("%d\n",max);
	return 0;
}