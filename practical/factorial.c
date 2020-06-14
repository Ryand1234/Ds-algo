#include<stdio.h>

int fac(int n)
{
	if(n == 0)
	       return 1;

	return n*fac(n-1);	
}

int main()
{
	int n;
	printf("Enter Number to find Factorial: ");
	scanf("%d", &n);

	printf("Factorial is %d\n", fac(n));
	return 0; 
}
