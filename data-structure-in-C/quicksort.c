#include <stdio.h>

int partition(char A[], int l, int h)
{
	int pivot = l;
	char k;
	for (int i = l; i < h; i++)
	{
		if(A[i] < A[h])
		{
			k = A[i];
			A[i] = A[pivot];
			A[pivot] = k;
			pivot++;
		}
	}
	k = A[h];
	A[h] = A[pivot];
	A[pivot] = k;
	
	return pivot;
}

void quicksort(char A[], int l, int h)
{
	int p;
	if((h-l)>0)
	{
		p = partition(A, l, h);
		quicksort(A, l, p-1);
		quicksort(A, p+1, h);
	}
}

int main()
{
	char A[] = {'Q', 'U', 'I', 'C', 'K', 'S', 'O', 'R', 'T'};
	int n = 9;
	printf("Initial\n");
	for (int i = 0; i < n; i++)
	{
		printf("%c ", A[i]);
	}
	quicksort(A, 0, n-1);
	printf("\nSorted\n");
	for (int i = 0; i < n; i++)
	{
		printf("%c ", A[i]);
	}
	printf("\n");
	return 0;
}