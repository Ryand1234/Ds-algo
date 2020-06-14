#include<stdio.h>

int main()
{
	int A[] = { 4, 1, 5, 2, 7, 6, 9};
	int n = 7, i, s;

	printf("Given Array is\n");
	for( i = 0; i < 7; i++)
		printf("%d ", A[i]);
	printf("\n");

	printf("Enter number to find: ");
	scanf("%d", &s);

	for(i = 0;  i < 7; i++)
	{
		if(A[i] == s)
		{
			printf("Number found at position %d \n", i);
			return 0;
		}
	}

	printf("Number not found\n");
	return 0; 
}
