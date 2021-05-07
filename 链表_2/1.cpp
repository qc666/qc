#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct infor{
	char name[10];
	int age;
	float score;
	struct infor* next;
};

//创建链表，并接收数据：
struct infor* link(int len)
{
	struct infor* end,*body,*head;
	head=(struct infor*)malloc(sizeof(struct infor));
	end=head;
	for(int i=0;i<len;i++)
	{
		body=(struct infor*)malloc(sizeof(struct infor));
		printf("请输入学生姓名：\nname:");
		scanf("%s",body->name);
		printf("请输入学生年龄：\nage:");
		scanf("%d",&body->age);
		printf("请输入学生分数：\nscore:");
		scanf("%f",&body->score);
		end->next=body;
		end=body;
	}
	end->next=NULL;
	return head;
}

//输出学生数据：
void output (struct infor* head)
{
	struct infor* body;
	int i=0;
	body=head->next;
	while(body!=NULL)
	{
		i++;
		printf("第%d位学生信息：\n",i);
		printf("学生姓名：%-5s",body->name);
		printf("学生年龄：%-3d",body->age);
		printf("学生成绩：%-4.2f",body->score);
		body=body->next;
		printf("\n");
	}
}

//排序：
struct infor* sort(struct infor* head)
{
	struct infor* p,* p1,p2;
	p=head;
	p=head->next;
	while(p->next!=NULL)
	{
		p1=p->next;
		if(p->score<p->next->score)
		{
			p2.score=p1->score;
			p1->score=p->score;
			p->score=p2.score;
			strcpy(p2.name,p1->name);
			strcpy(p1->name,p->name);
			strcpy(p->name,p2.name);
			p2.age=p1->age;
			p1->age=p->age;
			p->age=p2.age;
		}
		p=p->next;
	}
	return head;
}

int main()
{
	struct infor* head=NULL;
	int len;
	printf("请输入学生个数：\nlen=");
	scanf("%d",&len);
	head=link(len);
	printf("\n\n");
	output(head);
	printf("按成绩高矮顺序排列：\n");
	head=sort(head);
	output(head);
	printf("\n");
	return 0;
}