#include<stdio.h>
#include<stdlib.h>
void main()
{
	int i,n;
	printf("请输入一维数组的个数：\n");
	scanf("%d",&i);
	int* arr=(int*)malloc(i*sizeof(int));
	printf("请输入一维数组：\n");
	for(n=0;n<i;n++)
		scanf("%d",arr+n);
	for(n=0;n<i;n++)
		printf("%d\n",arr[n]);
//	realloc(arr,100);
	printf("%d\n",sizeof(arr[0]));
}
	
	
