#include <stdio.h>
#include <stdlib.h>
void main()
{
	double a,b;
	int i=0;
	char c;
	while(1)
	{
		printf("输入算式：\n");
		scanf("%lf%c%lf",&a,&c,&b);
		switch(c)
		{
		case '+':
			printf("输出结果为：%lf\n",a+b);
			break;
		case '-':
			printf("输出结果为：%lf\n",a-b);
			break;
		case '/':
			printf("输出结果为：%lf\n",a/b);
			break;
		case '*':
			printf("输出结果为：%lf\n",a*b);
			break;
		default:
			printf("输入错误，请重新输入：\n"); 
		}
	}
	system("pause");
}
