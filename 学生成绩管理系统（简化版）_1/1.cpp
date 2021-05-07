#include<stdio.h>
#include<stdlib.h>

struct student{
	char name[30];
	int age;
	float grade;
};

// 给这几个学生的成绩排序并输出 
void sortstudent(struct student* Parr2,int len)
{
	struct student t;
	for(int i=0;i<len-1;i++)
	{
		for(int j=0;j<len-1-i;j++)
		{
			if(Parr2[j].grade<Parr2[j+1].grade)
			{
				t=Parr2[j];
				Parr2[j]=Parr2[j+1];
				Parr2[j+1]=t;
			}
		}
	}
	printf("\n");
	printf("\n");
	printf("该名次为：\n");
	for( i=0;i<len;i++)
	{
		printf("第%d名  ",i+1); 
		printf("姓名：%-20s  ",Parr2[i].name);
		printf("年龄：");
		printf("%2d  ",Parr2[i].age);
		printf("成绩：");
		printf("%.2f  ",Parr2[i].grade);
		printf("\n");
	}
}

//下为输入学生信息的函数
void inputstudent(struct student* Parr1,int len)
{
	for(int i=0;i<len;i++)
	{
		printf("请输入第%d个学生的信息：\n",i+1);
		printf("该生名字：");
		scanf("%s",Parr1[i].name);
		printf("该生年龄：");
		scanf("%d",&Parr1[i].age);
		printf("该生成绩：");
		scanf("%f",&Parr1[i].grade);
	}
	sortstudent(Parr1,len);						//给这几个学生的成绩排序 并输出 

}

int main()
{
	int len;
	struct student* Parr;
	printf("请输入学生个数：\nlen=");
	scanf("%d",&len);
	Parr=(struct student*)malloc(len*sizeof(struct student));
	//下面为输入学生信息。
	inputstudent(Parr,len); 
	free(Parr);
	system("pause");
	return 0;

}