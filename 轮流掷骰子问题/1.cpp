#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void main()
{
	int a=0,b=0,n,m;
	int num=0,nam=0;
	srand(time(NULL));
	printf("请输入进行多少盘游戏，一盘游戏每个人掷骰子多少次：\n");
	scanf("%d",&n);
	scanf("%d",&m);
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			a+=rand()%7;
			b+=rand()%7;
		}
		if(a>b)
			num++;
		if(b>a)
			nam++;
		a=0;b=0;
	}
	if(num>nam)
		printf("第一个人获胜！");
	else if(nam>num)
		printf("第二个人获胜！");
	else
		printf("平局！");
	printf("\n");
	system("pause");
}
/*
			两个人掷骰子:确定每盘投掷次数以及
			投掷盘数后，用计算机模拟最终结果
*/

			
