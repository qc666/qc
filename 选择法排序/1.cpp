#include<stdio.h>
void main()
{
	int x[1000],i,j,k,a,t,max;
	printf("请输入数字（负数结束）：\n");
	for(i=0;i<1000;i++)
	{
		scanf("%d",&x[i]);
		if(x[i]<0)
			break;
	}
	for(j=0;j<=i-1;j++)
	{
		printf("%d ",x[j]);
	}
	printf("\n");
	for(j=0;j<=i-1;j++)
	{
		max=x[j];
		a=j;
		for(k=a+1;k<=i-1;k++)
		{
			if(x[k]>x[a])
			{
				max=x[k];
				a=k;
			}
		}
		x[a]=x[j];
		x[j]=max;
	}
	for(j=0;j<=i-1;j++)
		printf("%d ",x[j]);
}






