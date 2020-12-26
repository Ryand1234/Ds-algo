#include <stdio.h>
#include <limits.h>
#include <string.h>
#define MAX 20
int parent[MAX], rightChild[MAX], leftChild[MAX];

int min(int a, int b)
{
	return (a > b)? b : a;
}

int getMin(int A[], int n, int p, int q)
{
	if(p == q)
		return A[p];
	if(parent[p] == -1)
		return min(A[p], getMin(A, n, p+1, q));

	return getMin(A, n, p+1, q);
}

void createCartesianTree(int A[], int n)
{
	memset(parent, -1, sizeof(parent));
	memset(leftChild, -1, sizeof(leftChild));
	memset(rightChild, -1, sizeof(rightChild));

	int root = 0, last;

	int index = 0;

	for (index = 0; index < n; index++)
	{
		last = index - 1;

		if(rightChild[root] == -1 && leftChild[root] == -1 && parent[root] == -1)
			parent[root] = index;
		else {
			if(A[last] > A[index]) {
				leftChild[index] = last;
				parent[last] = index;
			} else {
				parent[index] = last;
				rightChild[last] = index;
			}
		}
	}

	printf("Parent Array\n");
	for(index = 0; index < n; index++)
	{
		printf("%d->%d\n", index, parent[index]);
	}
	printf("\nleft Child\n");
	for(index = 0; index < n; index++)
	{
		printf("%d->%d\n", index, leftChild[index]);
	}
	printf("\nRight Child\n");
	for(index = 0; index < n; index++)
	{
		printf("%d->%d\n", index, rightChild[index]);
	}
}

int main()
{
	int input[] = {9, 4, 6, 3, 5, 2, 1, 8};
	int n = 8;
	printf("Given Array\n");
	printf("9, 4, 6, 3, 5, 2, 1, 8\n");
	createCartesianTree(input, n);
	printf("Min: %d\n", getMin(input, n, 3, 5));
	return 0;
}