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
