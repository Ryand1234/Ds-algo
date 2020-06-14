#include<stdio.h>

void bubble(int A[], int n)
{
 	int i, j;
	int check = 1;
	while(check == 1)
	{
		check = 0;
		for(i = 1; i < n; i++)
		{
			if(A[i-1] > A[i])
			{
				j = A[i];
				A[i] = A[i-1];
				A[i-1] = j;
				check = 1;
			}	
		}
	}
}

int main()
{
	int n = 10;
	int A[10];

	int i, j;
	printf("Enter 10 Numbers: \n");
	for(i = 0; i < n; i++)
                scanf("%d ", &A[i]);

	for(i = 0; i < n; i++)
		printf("%d ", A[i]);
	printf("\n");

	bubble(A, n);

	printf("Greatest of all 10 digits is %d\n", A[9]);

	return 0; 
}
