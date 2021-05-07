#include<stdio.h>
void average(double* a,int n)
{
	double sun= 0;
	for(int i=0;i<n;i++)
	{
		sun=sun+a[i];
	}
	    printf("平均成绩为: %.1lf\n", sun/n);
}
void max(double* p,int n)
{
	double max=0,a;
	for(int i=0;i<10;i++)
	{
		if(p[i]>max)
		{
			max=p[i];
			a=i;
		}
	}
	printf("最高成绩为:%.0lf \n该生序号为:%.0lf\n" ,max,a+1);
}	
void main()
{
	double a[10];
	printf("请输入10个人的成绩: \n");
	for(int i=0;i<10;i++)
		scanf("%lf",&a[i]);
	average(a,10);
	max(a,10);
}