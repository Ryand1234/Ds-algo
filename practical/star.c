#include<stdio.h>

int main()
{
	int n, i, j, k;
	printf("Enter Height: ");
	scanf("%d", &n);

	for(i = 1; i <= n; i++)
	{
		for(j = n; j > i; j--)
			printf(" ");
		k = i*2 -1;
		for(j = 1; j <= k; j++)
			printf("*");
		printf("\n");
	}
	return 0; 
}
