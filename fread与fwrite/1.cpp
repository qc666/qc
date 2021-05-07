#include <stdio.h>

typedef struct student
{
	char name[30];
	char age[20];
}stu;
void main()
{
//	char a[2][50];
	stu stu1,stu[3]={{"z","20"},
			{"a","30"},
			{"b","40"},	};
	FILE *fp = fopen("D:\\b.txt", "r+");
//	fwrite(&stu,sizeof(stu),3,fp);
	fread(stu,sizeof(stu),3,fp);
//	printf("%s %s\n",a[0],a[1]);				无法定义其他类型的指针变量来接受文件内容
	printf("%-30s %-20s\n",stu[1].name,stu[1].age);
}