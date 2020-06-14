#include<stdio.h>
#include<string.h>
#define MAX 15

void pal(char s[])
{
	 int len = strlen(s);

	 for(int i = 0; i < len/2; i++)
	 {
		 k = len - 2 - i;
		 if(s[i] != s[k])
		 {
			 printf("String is not pallindrom\n");
			 return ;
		 }
	 }

	 printf("String is Pallindrom\n");
}

int main()
{
	char s[MAX];
	fgets(s, MAX, stdin);

	pal(s);
	return 0; 
}
