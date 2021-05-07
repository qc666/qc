#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int menu();
void ini(struct student * head);
void input(struct student * head);
void find();
void add();
void del();
struct student * ref();
void sort();
void output(struct student *head);
struct student * creat(struct student *head);
struct student * ref1();

//一个储存学生信息的结构体
struct student{
	char stu_id[20];
	char name[20];
	int age;
	float english;
	float math;
	float chinese;
	float pe;
	struct student *next;
};

int main()
{
	struct student * head=NULL;
	head=(struct student *)malloc(sizeof(struct student));
	int i;
	i=menu();
	switch(i)
	{
	case 1:
		ini(head);               //初始化学生信息
		break;
	case 2:
		find();              //查询全部学生信息
		break;               
	case 3:
		add();				 //添加学生信息
		break;
	case 4:
		del();               //删除学生信息
		break;
	case 5:
		ref();               //刷新学生信息
		break;
	case 6:
		sort();              //给学生按照学号先后排序
		break;
	case 7:
		system("cls");
		printf("系统已退出，欢迎再次使用！\n");              //退出该系统
		system("pause");
		return 0;
	}
	system("pause");
	return 0;
}

// 选择菜单：
int menu()
{
	int num;
	printf("***************************************************************************************\n");
	printf("***************************************************************************************\n");
	printf("*******************************     学生信息管理系统      *****************************\n");
	printf("***************************************************************************************\n");
	printf("*******************************   1.初始化学生信息        *****************************\n");
	printf("*******************************   2.查询学生信息          *****************************\n");
	printf("*******************************   3.添加学生信息          *****************************\n");
	printf("*******************************   4.删除学生信息          *****************************\n");
	printf("*******************************   5.刷新学生信息          *****************************\n");
	printf("*******************************   6.排序学生信息（按学号）*****************************\n");
	printf("*******************************   7.退出信息系统          *****************************\n");
	printf("*******************************  帮助：使用前请先初始化   *****************************\n");
	printf("***************************************************************************************\n");
	printf("***************************************************************************************\n");
	printf("\n");
	while(1)
	{
		printf("请输入你的选择：");
		scanf("%d",&num);											
		if(num>=1&&num<=7)
			break;
		else
			printf("error！try again！！\n");
	}
	system("cls");
	return num;
}

void ini(struct student * head)
{
	char ch1,ch;
	ch1=getchar();
	struct student* end,* body;
	end=head;
    FILE *fp=fopen("学生成绩.txt","rb+");
	body=(struct student *)malloc(sizeof(struct student));
	if(fread(body,sizeof(struct student),1,fp)!=1)
	{
		fclose(fp);
		printf("未查询到学生信息，请重新创建\n");
		printf("\n");
		input(head);
	}
	else
	{
		fclose(fp);
		printf("查询到学生信息，是否输出（Y or N）?\n");
		while(1)
		{
			printf("请输入你的选择：");
			ch=getchar();
			ch1=getchar();                                           //吞掉垃圾字符
			if(ch=='Y')
			{
				ref();
				break;
			}
			else if(ch=='N')
			{
				system("cls");
				main();
				break;
			}
			else
				printf("error! try again!!\n");
		}
	}
}

void input(struct student * head)
{
	struct student* end,* body;
	end=head;
	FILE *fp=fopen("学生成绩.txt","wb+");
	printf("请输入学生信息（学号为-1时结束）：\n");
	while(1)
	{
			body=(struct student *)malloc(sizeof(struct student));
			printf("学生学号：");
			scanf("%s",body->stu_id);
			if(strcmp(body->stu_id,"-1")==0)
				break;
			printf("学生姓名：");
			scanf("%s",body->name);
			printf("学生年龄：");
			scanf("%d",&body->age);
			printf("学生英语成绩：");
			scanf("%f",&body->english);
			printf("学生数学成绩：");
			scanf("%f",&body->math);
			printf("学生语文成绩：");
			scanf("%f",&body->chinese);
			printf("学生体育成绩：");
			scanf("%f",&body->pe);
			fwrite(body,sizeof(struct student),1,fp);
			end->next=body;
			end=body;
	}
	end->next=NULL;
	fclose(fp);
	printf("\n是否返回主菜单（Y or N）:\n");
	char ch,ch2;
	ch2=getchar();
	while(1)
	{
		printf("请输入你的选择：");
		ch=getchar();
		ch2=getchar();
		if(ch=='N')
			{
				system("cls");
				printf("系统已退出，欢迎再次使用！\n");              //退出该系统
				system("pause");
				break;
			}
		else if(ch=='Y')
			{
				system("cls");
				main();
				break;
			}
		else
			printf("error! try again!!\n");
	}
}

void find()
{
	struct student * head=NULL;
	head=ref1();
	if(head==0)
	{
		while(1)
		{
			printf("\n是否添加学生信息（Y or N）:\n");
			char ch,ch2;
			ch2=getchar();
			ch=getchar();
			if(ch=='N')
				{
					system("cls");
					printf("系统已退出，欢迎再次使用！\n");              //退出该系统
					system("pause");
					return;
				}
			else if(ch=='Y')
				{
					system("cls");
					add();
					break;
				}
			else
				printf("error! try again!!\n");
		}
	}
	printf("请输入要查找的学生的学号：\n");
	char ch1[20];
	scanf("%s",ch1);
	struct student *body;
	body=head->next;
	while(body!=NULL)
	{
		if(strcmp(ch1,body->stu_id)==0)
		{
			printf("\n该学生的信息为：\n");
			printf("学号：%-20s 姓名：%-20s 年龄：%-3d 英语：%-5.2f 数学：%-5.2f 语文：%-5.2f 体育：%-5.2f\n",\
					body->stu_id,body->name,body->age,body->english,body->math,body->chinese,body->pe);
			break;
		}
		body=body->next;
	}
	if(body==NULL)
		printf("查无此人！\n");
	system("pause");
	while(1)
	{
		printf("\n是否返回主菜单（Y or N）:\n");
		char ch,ch2;
		ch2=getchar();
		ch=getchar();
		if(ch=='N')
			{
				system("cls");
				printf("系统已退出，欢迎再次使用！\n");              //退出该系统
				system("pause");
				break;
			}
		else if(ch=='Y')
			{
				system("cls");
				main();
				break;
			}
		else
			printf("error! try again!!\n");
	}
}


void add()
{
	FILE* fp=fopen("学生成绩.txt","ab");
	struct student stu;
	printf("请输入学生信息（学号为-1时结束）：\n");
	while(1)
	{
			printf("学生学号：");
			scanf("%s",stu.stu_id);
			if(strcmp(stu.stu_id,"-1")==0)
			{
				printf("添加失败！！\n");
				break;
			}
			printf("学生姓名：");
			scanf("%s",stu.name);
			printf("学生年龄：");
			scanf("%d",&stu.age);
			printf("学生英语成绩：");
			scanf("%f",&stu.english);
			printf("学生数学成绩：");
			scanf("%f",&stu.math);
			printf("学生语文成绩：");
			scanf("%f",&stu.chinese);
			printf("学生体育成绩：");
			scanf("%f",&stu.pe);
			if(fwrite(&stu,sizeof(struct student),1,fp)==1)
				printf("添加成功！！\n");
	}
	fclose(fp);
	system("pause");
	while(1)
	{
		printf("\n是否返回主菜单（Y or N）:\n");
		char ch,ch2;
		ch2=getchar();
		ch=getchar();
		if(ch=='N')
			{
				system("cls");
				printf("系统已退出，欢迎再次使用！\n");              //退出该系统
				system("pause");
				break;
			}
		else if(ch=='Y')
			{
				system("cls");
				main();
				break;
			}
		else
			printf("error! try again!!\n");
	}
}

void del()
{
	FILE* fp=fopen("学生成绩.txt","rb+");
	struct student *head,*end,*body1,*body,stu,*p;
	head=(struct student*)malloc(sizeof(struct student));
	end=head;
	if(fread(&stu,sizeof(struct student),1,fp)!=1)
	{
		printf("没有学生信息\n");
		fclose(fp);
		return;
	}
	rewind(fp);
	while(fread(&stu,sizeof(struct student),1,fp)==1)
	{
		body1=(struct student*)malloc(sizeof(struct student));
		strcpy(body1->stu_id,stu.stu_id);
		body1->age=stu.age;
		body1->chinese=stu.chinese;
		body1->english=stu.english;
		body1->math=stu.math;
		body1->pe=stu.pe;
		strcpy(body1->name,stu.name);
		end->next=body1;
		end=body1;
	}
	end->next=NULL;
	fclose(fp);
	output(head);
	FILE* fp1=fopen("学生成绩.txt","wb+");
	printf("请输入需要删除的学生的学号：\n");
	scanf("%s",stu.stu_id);
	p=head;
	body=p->next;
	while(body!=NULL)
	{
		if(strcmp(stu.stu_id,body->stu_id)==0)
		{
			p->next=body->next;
			free(body);
			break;
		}
		p=body;
		body=body->next;
	}
	if(body==NULL)
		printf("该学生不存在！！\n");
	else
		printf("删除成功！！\n");
	body=head->next;
	while(body!=NULL)
	{
		fwrite(body,sizeof(struct student),1,fp1);
		body=body->next;
	}
	fclose(fp1);
	system("pause");
	while(1)
	{
		printf("\n是否返回主菜单（Y or N）:\n");
		char ch,ch2;
		ch2=getchar();
		ch=getchar();
		if(ch=='N')
			{
				system("cls");
				printf("系统已退出，欢迎再次使用！\n");              //退出该系统
				system("pause");
				break;
			}
		else if(ch=='Y')
			{
				system("cls");
				main();
				break;
			}
		else
			printf("error! try again!!\n");
	}
}

struct student * ref()
{
	struct student *head,*body1,*end,stu;
	FILE *fp=fopen("学生成绩.txt","rb+");
	head=(struct student*)malloc(sizeof(struct student));
	end=head;
	while(fread(&stu,sizeof(struct student),1,fp)==1)
	{
		body1=(struct student*)malloc(sizeof(struct student));
		strcpy(body1->stu_id,stu.stu_id);
		body1->age=stu.age;
		body1->chinese=stu.chinese;
		body1->english=stu.english;
		body1->math=stu.math;
		body1->pe=stu.pe;
		strcpy(body1->name,stu.name);
//		printf("学号：%-20s 姓名：%-20s 年龄：%-3d 英语：%-5.2f 数学：%-5.2f 语文：%-5.2f 体育：%-5.2f\n",\
				body1->stu_id,body1->name,body1->age,body1->english,body1->math,body1->chinese,body1->pe);
		end->next=body1;
		end=body1;
	}
	end->next=NULL;
	rewind(fp);
	if(fread(&stu,sizeof(struct student),1,fp)!=1)
	{
		printf("没有学生信息\n");
		fclose(fp);
		return 0;
	}
	fclose(fp);
	output(head);
	char ch,ch2;
	ch2=getchar();
	while(1)
	{
		printf("\n是否返回主菜单（Y or N）:\n");
		ch=getchar();
		ch2=getchar();
		if(ch=='N')
			{
				system("cls");
				printf("系统已退出，欢迎再次使用！\n");              //退出该系统
				system("pause");
				break;
			}
		else if(ch=='Y')
			{
				system("cls");
				main();
				break;
			}
		else
			printf("error! try again!!\n");
	}
	return head;
}

void sort()
{
	struct student *head,*body,*body1,p1;
	head=ref1();
	if(head==0)
		return ;
	body=head->next;
	while(body->next!=NULL)
	{
		body1=body;
		while(body1!=NULL)
		{
			if(strcmp(body->stu_id,body1->stu_id)>0)
			{
				strcpy(p1.stu_id,body->stu_id);
				strcpy(body->stu_id,body1->stu_id);
				strcpy(body1->stu_id,p1.stu_id);
				p1.age=body->age;
				body->age=body1->age;
				body1->age=p1.age;
				p1.chinese=body->chinese;
				body->chinese=body1->chinese;
				body1->chinese=p1.chinese;
				p1.english=body->english;
				body->english=body1->english;
				body1->english=p1.english;
				p1.math=body->math;
				body->math=body1->math;
				body1->math=p1.math;
				strcpy(p1.name,body->name);
				strcpy(body->name,body1->name);
				strcpy(body1->name,p1.name);
				p1.pe=body->pe;
				body->pe=body1->pe;
				body1->pe=p1.pe;
			}
			body1=body1->next;
		}
		body=body->next;
	}
	printf("学号从小到大排序");
	output(head);
	char ch,ch2;
	ch2=getchar();
	while(1)
	{
		printf("\n是否返回主菜单（Y or N）:\n");
		ch=getchar();
		ch2=getchar();
		if(ch=='N')
			{
				system("cls");
				printf("系统已退出，欢迎再次使用！\n");              //退出该系统
				system("pause");
				break;
			}
		else if(ch=='Y')
			{
				system("cls");
				main();
				break;
			}
		else
			printf("error! try again!!\n");
	}
}

void output(struct student *head)
{
	struct student * body;
	body=head->next;
	printf("\n\n各个学生信息为：\n");
	while(body!=NULL)
	{
		printf("学号：%-20s 姓名：%-20s 年龄：%-3d 英语：%-5.2f 数学：%-5.2f 语文：%-5.2f 体育：%-5.2f\n",\
				body->stu_id,body->name,body->age,body->english,body->math,body->chinese,body->pe);
		body=body->next;
	}
}

struct student * ref1()
{
	struct student *head,*body1,*end,stu;
	FILE *fp=fopen("学生成绩.txt","rb+");
	head=(struct student*)malloc(sizeof(struct student));
	end=head;
	while(fread(&stu,sizeof(struct student),1,fp)==1)
	{
		body1=(struct student*)malloc(sizeof(struct student));
		strcpy(body1->stu_id,stu.stu_id);
		body1->age=stu.age;
		body1->chinese=stu.chinese;
		body1->english=stu.english;
		body1->math=stu.math;
		body1->pe=stu.pe;
		strcpy(body1->name,stu.name);
//		printf("学号：%-20s 姓名：%-20s 年龄：%-3d 英语：%-5.2f 数学：%-5.2f 语文：%-5.2f 体育：%-5.2f\n",\
				body1->stu_id,body1->name,body1->age,body1->english,body1->math,body1->chinese,body1->pe);
		end->next=body1;
		end=body1;
	}
	end->next=NULL;
	rewind(fp);
	if(fread(&stu,sizeof(struct student),1,fp)!=1)
	{
		printf("没有学生信息\n");
		fclose(fp);
		return 0;
	}
	fclose(fp);
	return head;
}
