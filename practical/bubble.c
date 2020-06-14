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
	int A[10] = {2, 4, 1, 3, 9, 45, 5, 44, 32, 20};

	int i, j;
	printf("Before Sort\n");
	for(i = 0; i < n; i++)
		printf("%d ", A[i]);
	printf("\n");

	bubble(A, n);

	printf("After Sort\n");
	for(i = 0; i < n; i++)
		printf("%d ", A[i]);
	printf("\n");

	return 0; 
}
