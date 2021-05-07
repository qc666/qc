#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main()
 {
 	char str[2][30];
 	int i=0;
 	for(i=0;i<2;i++)
 		gets(str[i]);
 	printf("%s%s\n",str[0],str[1]);
	strcat(str[0],str[1]);
	printf("%s\n",str[0]);
 	return 0;
}
