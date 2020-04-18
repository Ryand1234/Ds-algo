#include<cstdio>
#include<cstdlib>

void swap (int &a, int &b)
{
	int c;

	c = b;
	b = a;
	a = c;
}

void print(int A[], int n)
{

	for(int i = 0; i < n; i++)
		printf("%d->",A[i]);
	printf("\n");
}

void sort(int A[], int n)
{
	int cont = 0,i,j,loop=0;

	while(true)
	{
		loop++;
		cont = 0;

		for(i = 1; i < n; i++)
		{
			if(A[i-1] > A[i])
			{
				swap(A[i-1], A[i]);
				cont++;
			}

		}

		printf("Loop: %d\n",loop);
		print(A, n);

		if(cont == 0)
			break;
	}
}

int main()
{
	int n,i;
	printf("Enter Size: ");
	scanf("%d",&n);
	int A[n];

	for(i = 0; i < n; i++)
		scanf("%d",&A[i]);

	
	printf("Before Sorting\n");
	print(A,n);

	sort(A, n);

	printf("After Sorting\n");
	for(i = 0; i < n; i++)
		printf("%d->",A[i]);
	
	printf("\n");

	return 0;

}
