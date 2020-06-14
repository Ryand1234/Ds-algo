#include<stdio.h>
void fib(int n)
{
	int a = 0, b = 1, c;;
	for(int i = 0; i < n; i++)
	{
		printf("%d ",a);
		c = b;
		b = a + b;
		a = c;
	}
	printf("\n");
}

int main()
{
	int n;
	printf("Enter the nth term: ");
	scanf("%d", &n);
	fib(n);
	return 0; 
}
