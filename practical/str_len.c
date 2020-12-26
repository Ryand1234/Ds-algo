#include<stdio.h>
#define MAX 20

void len(char str[])
{
	int len = 0;
 	while(str[len] != '\0')
	{	
		len++;
	}

	printf("Length of String is %d\n", --len);
}

int main()
{
	char str[MAX];
	printf("Enter String: ");
	fgets(str, MAX, stdin);
	len(str);
	return 0; 
}
