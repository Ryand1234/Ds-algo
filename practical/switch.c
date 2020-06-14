#include<stdio.h>

int main()
{
	int t;
	printf("\t\tUsage of Switch Case\n");
	printf("\t\t1. Print Hello, World\n");
	printf("\t\t2. Print Hello, Globe\n");
	printf("\t\tChoice: ");
	scanf("%d", &t);
	switch(t)
	{
		case 1: printf("\t\tHello, World\n");
			break;
		case 2: printf("\t\tHello, Globe\n");
			break;
		default: printf("\t\tWrong Choice.\n\t\tRe-Run Program to choice another option\n");
	}
	return 0; 
}
