#include <stdio.h>
#include <stdlib.h>

struct Dome{
	int age;
	struct Dome* next;
};

//创建一个链表：
struct Dome* linkDome(int len)
{
	struct Dome* end,*head,*body;
	head=(struct Dome*)malloc(sizeof(struct Dome));
	end=head;
	for(int i=0;i<len;i++)
	{
		body=(struct Dome*)malloc(sizeof(struct Dome));
		printf("请输入年龄\nage=");
		scanf("%d",&body->age);
		end->next=body;
		end=body;
	}
	end->next=NULL;
	return head;
}

//输出该链表：
void output(struct Dome* head)
{
	struct Dome* r;
	r=head;
	r=r->next;
	while(r!=NULL)
	{
		printf("%d\n",r->age);
		r=r->next;
	}
}

//删除任意位置的节点：
void deletelink(struct Dome*head,int n)
{
	struct Dome*body,*p;
	body=head;
	int i=0;
	while(i<n&&body->next!=NULL)
	{
		p=body;
		body=p->next;
		i++;
	}
	if(body->next!=NULL)
	{
		p->next=body->next;
		free(body);
	}
	else
		printf("该节点不存在！！\n");
}

//插入某一个位置的节点：
void insert(struct Dome* head,int n)
{
	struct Dome* p,*pr;
	p=head;
	int i=0;
	p=head->next;
	while(i<n&&p!=NULL)
	{
		pr=p->next;
		p=pr;
		i++;
	}
	if(pr!=NULL)
	{
		pr=p->next;
		struct Dome* prr;
		prr=(struct Dome*)malloc(sizeof(struct Dome));
		printf("请输入该新增节点的值：\nage=");
		scanf("%d",&prr->age);
		prr->next=pr;
		p->next=prr;
	}
}

void found(struct Dome* head)
{

}

int main()
{
	struct Dome* head=NULL;
	printf("请输入链表数量：\n");
	int len,n;
	scanf("%d",&len);
	head=linkDome(len);
	output(head);
/*	
	printf("请输入需要删除的节点位置：\nn=");
	scanf("%d",&n);
	deletelink(head,n);
	output(head);
	printf("请输入需要插入的节点位置：\nn=");
	scanf("%d",&n);
	insert(head,n);
	output(head);
	*/
	printf("请输入查找的");
	found(head);
	return 0;
}
