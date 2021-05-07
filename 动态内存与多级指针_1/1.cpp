#include<stdio.h>
#include<stdlib.h>

void f(int** q)					//*q=&p;再由**q指向原&p的地址；
{
	*q=(int*)malloc(4);			/*找一个动态内存，
									该内存不会被程序自动释放；可由程序员手动释放；且可以通过free语句释放.*/	
	**q=3;
//	free(q);
}

void g(int** p)					//同上
{
	*p=(int*)malloc(4);								
	**p=5;
//	free(p);
}

/*
void h(int** f)
{
	int i=6;
	*f=&i;						  这种静态内存的写法 虽然没有报错，但是当h()这个函数运行完成时，
							      程序就已经将此静态内存&i释放掉了；故34行*p指向的地址（内存）已经非法了
}
*/

int main()
{
	int* p;	
	printf("%#x\n",p);			//含义：指针变量p的值；					
	printf("%#x\n",&p);			//含义：？？？
	f(&p);						
	printf("%d\n",*p);
//	free((int*)p);
//	free(&p);					//把&p(**q所指向的内容)释放掉
	g(&p);
	printf("%d\n",*p);
//	free(&p);
/*	h(&p);
	printf("%d\n",*p);    */      //	34行
	return 0;
}