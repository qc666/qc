#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define row 3
#define col 3

void select(char arr[row][col]);
void drow(char arr[row][col]);
void judge(char arr[row][col]);
void computer(char arr[row][col]);
void player2(char arr[row][col]);
void game(char arr[row][col]);
void game1(char arr[row][col]);
void game2(char arr[row][col]);
int winner(char arr[row][col]);
int isfull(char arr[row][col]);
void player1(char arr[row][col]);
void Game(char arr[row][col]);
void Game1(char arr[row][col]);
void MODE(char arr[row][col]);

int main()
{
	char arr[row][col]={'0','0','0','0','0','0','0','0','0'};
	select(arr);
	system("pause");
	return 0;
}

//玩家1下棋：
void player1(char arr[row][col])
{
	while(1)
	{
		int x,y;
		printf("请选择你的下棋位置（x,y）： ");
		scanf("%d%d",&x,&y);
		x=x-1;
		y=y-1;
		if(x>row-1||y>col-1)
		{
			printf("不合法\n");
			continue;
		}
		if(arr[x][y]!='0')
		{
			printf("不合法\n");
			continue;
		}
		arr[x][y]='*';
		break;
	}
}

//玩家2下棋：
void player2(char arr[row][col])
{
	while(1)
	{
		int x,y;
		printf("请选择你的下棋位置（x,y）： ");
		scanf("%d%d",&x,&y);
		x=x-1;
		y=y-1;
		if(x>row-1||y>col-1)
		{
			printf("不合法\n");
			continue;
		}
		if(arr[x][y]!='0')
		{
			printf("不合法\n");
			continue;
		}
		arr[x][y]='#';
		break;
	}
}

//电脑下棋：
void computer(char arr[row][col])
{
	while(1)
	{
		int x,y;
		srand((unsigned int)time(NULL));
		x=rand()%row;
		y=rand()%col;
		if(arr[x][y]!='0')
		{
			continue;
		}
		arr[x][y]='#';
		break;
	}
}

//人机模式判断谁先下棋;
void judge(char arr[row][col])
{
	int i=0;
	printf("*********************************\n");
	printf("**********选择下棋顺序***********\n");
	printf("***********1.玩家先下************\n");
	printf("***********2.电脑先下************\n");
	printf("*********************************\n");+
	printf("请输入你的选择:\n");
	scanf("%d",&i);
	if(i==1)
		game1(arr);
	if(i==2)
		game2(arr);
}

//打印棋盘
void drow(char arr[row][col])
{
	int i;
	for(i=0;i<row;i++)
	{
		printf("+---+---+---+\n");
		printf("| %c | %c | %c |\n",arr[i][0],arr[i][1],arr[i][2]);
	}
	printf("+---+---+---+\n");
	printf("\n");
	printf("\n");
}

//开始选项
void select(char arr[row][col])
{
	int i;
	printf("********************************\n");
	printf("*************游戏菜单***********\n");
	printf("************1.开始游戏**********\n");
	printf("************2.退出游戏**********\n");
	printf("********************************\n");
	scanf("%d",&i);
	if(i==2)
	{
		printf("欢迎下次来玩！\n");
	}
	else if(i==1)
	{
		printf("\n");
		MODE(arr);
	}
}

//人机模式：
void game(char arr[row][col])
{
	drow(arr);
	judge(arr);
}

//真人对战：
void Game(char arr[row][col])
{
	drow(arr);
	Game1(arr);
}

//玩家与玩家对战：
void Game1(char arr[row][col])
{
	char iswinner;
	while(1)
	{
		system("cls");
		drow(arr);
		player1(arr);
		iswinner=winner(arr);
		if(iswinner!='p')
			break;
		system("cls");
		drow(arr);
		player2(arr);
		iswinner=winner(arr);
		if(iswinner!='p')
			break;
	}
	printf("最终结果：\n");
	drow(arr);
	if(iswinner=='*')
		printf("玩家1胜！！\n");
	if(iswinner=='#')
		printf("玩家2胜！！\n");
	if(iswinner=='g')
		printf("平局！！！\n");

}

//从玩家开始的情况：
void game1(char arr[row][col])
{
	char iswinner;
	while(1)
	{
		system("cls");
		drow(arr);
		player1(arr);
		iswinner=winner(arr);
		if(iswinner!='p')
			break;
		system("cls");
		drow(arr);
		computer(arr);
		iswinner=winner(arr);
		if(iswinner!='p')
			break;
	}
	printf("最终结果：\n");
	drow(arr);
	if(iswinner=='*')
		printf("你战胜了智障人机！！\n");
	if(iswinner=='#')
		printf("你竟然被智障人机战胜了！！\n");
	if(iswinner=='g')
		printf("你居然和智障人机平局！！！\n");


}

//从电脑开始的情况：
void game2(char arr[row][col])
{
	char iswinner;
	while(1)
	{
		system("cls");
		computer(arr);
		drow(arr);
		iswinner=winner(arr);
		if(iswinner!='p')
			break;
		system("cls");
		drow(arr);
		player1(arr);
		iswinner=winner(arr);
		if(iswinner!='p')
			break;
	}
	drow(arr);
	printf("最终结果：\n");
	if(iswinner=='*')
		printf("你战胜了智障人机！！\n");
	else if(iswinner=='#')
		printf("你竟然被智障人机战胜了！！\n");
	else if(iswinner=='g')
		printf("你居然和智障人机平局！！！\n");

}

//首先判断赢得情况：
int winner(char arr[row][col])
{
	for(int i=0;i<row;i++)
	{
		if(arr[i][0]!='0')
			if(arr[i][0]==arr[i][1]&&arr[i][1]==arr[i][2])
				return arr[i][0];
	}
	for(i=0;i<col;i++)
		if(arr[0][i]!='0')
			if(arr[0][i]==arr[2][i]&&arr[2][i]==arr[1][i])
				return arr[0][i];
	if(arr[0][0]!='0'&&arr[0][0]==arr[1][1]&&arr[1][1]==arr[2][2])
		return arr[0][0];
	if(arr[0][2]!='0'&&arr[0][2]==arr[1][1]&&arr[1][1]==arr[2][0])
		return arr[0][2];
	if(isfull(arr))
		return 'p';
	return 'g';
}

//判断棋盘是否已满
int isfull(char arr[row][col])
{
	int i=0,j=0;
	for(i=0;i<row;i++)
		for(j=0;j<col;j++)
			if(arr[row][col]=='0')
				return 0;
	return 1;
}

//模式选择：
void MODE(char arr[row][col])
{
	printf("********************************\n");
	printf("************模式选择************\n");
	printf("***********1.人机对战***********\n");
	printf("***********2.真人对战***********\n");
	printf("********************************\n");
	int i;
	printf("请输入你的选择：");
	scanf("%d",&i);
	if(i==1)
		game(arr);
	if(i==2)
		Game(arr);
}
