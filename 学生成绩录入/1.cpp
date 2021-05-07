#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
	int i,j,sum=0,c=0;
	int a[5][5],b[5];
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for(i=0;i<5;i++)
	{  
		printf("第%d位：",i+1);
		for(j=0;j<5;j++)
		{
			printf("%-4d",a[i][j]);
			sum++;
		}
		if(sum%5==0)
			printf("\n");
	}
	printf("平均成绩：");
	for(i=0;i<5;i++)
	{
		sum=0;
		for(j=0;j<5;j++)
		{
			sum+=a[i][j];
		}
		b[i]=sum/5.0;
		printf("%.2f ",sum/5.0);
	}
	printf("\n");
	sum=0;
	for(i=0;i<5;i++)
	{
		if(b[i]>=sum)
		{
			sum=b[i];
			c=i;
		}
	}
	printf("序号为：%d\n最高分为：%.1f\n",c,sum/1.0);
	system("pause");
	return 0;
}
/*
一班5名学生5门课成绩，求输出平均成绩最高的学生成绩以及该学生的序号
					78  82  93  74  65 
					91  82  72  76  67 
					100 90  85  72  98 
					67  89  90  65  78 
					77  88  99  45  89
*/
