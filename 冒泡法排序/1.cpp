#include <stdio.h>
void main()
{
	int x[1000],i,j,k,t;
	printf("请输入数字（负数结束）：\n");
	for(i=0;i<1000;i++)
	{
		scanf("%d",&x[i]);
		if(x[i]<0)
			break;
	}
	for(j=0;j<=i-1;j++)
	{
		for(k=j+1;k<i;k++)
		{
			if(x[k]>x[j])
			{
			t=x[k];
			x[k]=x[j];
			x[j]=t;
			}
		}
	}
	j=0;
	for(j=0;j<=i-1;j++)
		printf("%d ",x[j]);
}
				