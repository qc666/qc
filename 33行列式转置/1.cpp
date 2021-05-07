#include <stdio.h>
#include <stdlib.h>
int main()
{
	int arr[3][3],arr1[3][3];
	int i,j;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			scanf("%d",arr[i]+j);
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			arr1[j][i]=arr[i][j];
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%5d ",arr1[i][j]);
		}
		printf("\n");
	}
	return 0;
}


