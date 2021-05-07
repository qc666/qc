#include<stdio.h>
#include<string.h>
int main()
{
	char str[100];
	printf("ÇëÊäÈë×Ö·û´®:\n");
	gets(str);
	printf("Ô­×Ö·û´®Îª£º\n");
	for(int j=0;str[j]!='\0';j++)
		printf("%c",str[j]);
	printf("\n");
    printf("ÄæÐòºóµÄ×Ö·û´®Îª£º\n");
	for(int i=j-1;i>=0;i--)
		printf("%c",str[i]);
	printf("\n");
	return 0;
}
