#include<stdio.h>
#include<string.h>
int main()
{
	char str1[80],str2[80],string[80];
	int a;
	printf("********1.原文转密码      2.密码转原文********\n");
	printf("请输入想要转化的类型：\n");
	scanf("%d",&a);
	if(a==1)
	{
		gets(string);
		printf("请输入原文：\n");
		gets(str1);
		for(int i=0;str1[i]!='\0';i++)
		{
			if(str1[i]>='a'&&str1[i]<='z')
			{
				str2[i]=219-str1[i];
			}
			else if(str1[i]>='A'&&str1[i]<='Z')
			{
				str2[i]=155-str1[i];
			}
			else
				str2[i]=str1[i];
		}
		str2[i+1]='\0';
		printf("原文为：\n");
		printf("%s\n",str1);
		printf("得到的密码为：\n");
		printf("%s",str2);
		printf("\n");
	}
	if(a==2)
	{
		gets(string);
		printf("请输入密码：\n");
		gets(str1);
		for(int i=0;str1[i]!='\0';i++)
		{
			if(str1[i]>='a'&&str1[i]<='z')
			{
				str2[i]=219-str1[i];
			}
			else if(str1[i]>='A'&&str1[i]<='Z')
			{
				str2[i]=155-str1[i];
			}
			else
				str2[i]=str1[i];
		}
		str2[i+1]='\0';
		printf("密码为：\n");
		printf("%s\n",str1);
		printf("得到的原文为：\n");
		printf("%s",str2);
		printf("\n");
	}
	return 0;
}
