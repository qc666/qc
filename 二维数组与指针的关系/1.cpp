#include <stdio.h>
void main()
{
	int a[3][4]={1,2,3,4,5,6,7,8,9,10,11,22};
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<4;j++)
			printf("%5d",*(a[i]+j));
		printf("\n");
	}
}

