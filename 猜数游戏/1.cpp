#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main()
{
	long int a,b,i;
	srand(time(NULL));
	a=rand()%1000;
	printf("游戏开始\n请输入一个数：\n");
    while(1)
	{
		scanf("%ld",&b);
		if(b<a)
		{
			printf("你输入的数小了点，再输入一个大的试试：");
			continue;
		}
		if(b>a)
		{
			printf("你输入的数大了点，再输入一个小的试试：");
			continue;
		}
		if(a==b)
		{
			printf("恭喜你，猜对了！！！\n");
			break;
		}
	}
	system("pause");
	return 0;
}
