#include <stdio.h>
#include <stdlib.h>

void sort(float arr[]);

int main()
{
	float arr[1];
	sort(arr);
	system("pause");
	return 0;
}

void sort(float arr[])
{
	int n,j;
	float arr1;
	printf("请输入排序数的个数：\nn=");
	scanf("%d",&n);
	printf("请输入数字：\n");
	for(int i=0;i<n;i++)
		scanf("%f",arr+i);
	for(i=0;i<n;i++)
	{
		j=i;
		for(int k=i+1;k<n;k++)
		{
			if(arr[k]>arr[j])
				j=k;
		}
		arr1=arr[j];
		arr[j]=arr[i];
		arr[i]=arr1;
	}
	printf("从大到小顺序为：\n");
	for(i=0;i<n;i++)
		printf("%.2f ",arr[i]);
	printf("\n");
}