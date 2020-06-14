#include<stdio.h>

int main()
{
	int n, guess;
	printf("Enter Number for Check: ");
	scanf("%d", &n);

	for(guess = 2; guess*guess <= n; guess++)
	{
		if(n % guess != 0)
		{
			printf("%d is not a Prime Number\n", n);
			return 0;
		}
	}
	printf("%d is a Prime Number\n", n);
	return 0; 
}
