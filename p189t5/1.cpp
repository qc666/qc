#include<stdio.h>
#include<stdlib.h>
int main( )
{
	double a[5][4],c[5][4];
	double t,u=0,sum=0,b[5];
	int i,j,k,l;
	printf("请输入5个人的门课成绩: \n");
	for(i=0;i<5;i++)
		for(j=0;j<4;j++)
			scanf("%lf",&a[i][j]);
	printf("\n");
	for(int n=0;n<i;n++)
	{
		for(int m=0;m<j;m++)
		{
			sum+=a[n][m];
		}
		b[n]=sum/j;
		printf("%d学生的平均成绩为:%.2lf\n" ,n+1, sum/j);
		sum= 0;
	}
	for(k=0;k<n;k++)
		for(l=0;l<n-k;l++)
		{
			if(b[l]<b[l+1])
				{
					t=b[l];
					b[l]=b[l+1];
					b[l+1]=t;
					for(i=0;i<4;i++)
					{
						u=a[l][i];
						a[l][i]=a[l+1][i];
						a[l+1][i]=u;
					}
				}
		}
	printf("\n");
	printf("由大到小的成绩排序为：\n");
	for(i=0;i<5;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("%6.0lf",a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("从大到小排序为: \n");
	for(k=0;k<i;k++ )
		printf("%.2lf ",b[k]);
	printf("\n");
	system("pause");
	return 0;
}