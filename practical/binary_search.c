#include<stdio.h>

int main()
{
	int A[] = { 1, 2, 4, 5, 6, 7, 9};
	int n = 7, i, s;

	printf("Given Array is\n");
	for( i = 0; i < 7; i++)
		printf("%d ", A[i]);
	printf("\n");

	printf("Enter number to find: ");
	scanf("%d", &s);

	int first = 0;
	int last = 7;
	int mid;
	while(first <= last)
	{
		mid = ( first + last )/2;

		if(A[mid] == s)
		{
			printf("Number found at position %d \n", mid);
			return 0;
		}
		else{
			if(s > A[mid])
			{
				first = mid + 1;
			}
			else {
				last = mid - 1;
			}	
		}
	}

	printf("Number not found\n");
	return 0; 
}
