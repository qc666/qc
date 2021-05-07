#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void compare(int player,int computer);

int main()
{
	while(1)
	{
		printf("***********************************\n");
		printf("*************猜拳游戏**************\n");
		printf("************1.开始游戏*************\n");
		printf("************2.退出游戏*************\n");
		printf("***********************************\n");
		printf("请输入你的选择：\n");
		int i;
		scanf("%d",&i);
		if(i==1)
		{
			printf("请选择你要出的方式（1.拳头 2.剪刀 3.布）：");
			int player;
			scanf("%d",&player);
			int computer;
			srand((unsigned int) time(NULL));
			computer=rand()%3+1;
			compare(player,computer);
//			printf("%d\n",computer);
		}
		if(i==2)
		{
			printf("欢迎下次再来！\n");
			break;
		}
	}
	system("pause");
	return 0;
}

//判断:
void compare(int player,int computer)
{
	static int i=0,j=0,k=0;
	switch(player)
	{
	case 1:
		{
			if(computer==1)
			{	printf("平局！\n"); i++;}
			if(computer==2)
			{	printf("你赢了！\n"); j++;}
			if(computer==3)
			{	printf("电脑赢了！\n"); k++;}
			break;
		}
	case 2:
		{
			if(computer==2)
			{	printf("平局！\n");i++;}
			if(computer==3)
			{	printf("你赢了！\n");j++;}
			if(computer==1)
			{	printf("电脑赢了！\n");k++;}
			break;
		}
	case 3:
		{
			if(computer==3)
			{	printf("平局！\n");i++;}
			if(computer==1)
			{	printf("你赢了！\n");j++;}
			if(computer==2)
			{	printf("电脑赢了！\n");k++;}
			break;
		}
	}
	printf("\n具体结果为：\n");
	printf("平局%d次！\n",i);
	printf("你赢了%d次！\n",j);
	printf("电脑赢了%d次！\n",k);
	system("pause");
	system("cls");
}
