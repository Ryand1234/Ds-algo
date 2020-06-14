#include<stdio.h>

int reverse(int n)
{
	int reverse = 0;

	while(n)
	{
		reverse = reverse*10 + n%10;
		n /= 10;
	}

	return reverse;
}

int main()
{
	int n, rev;
	printf("Enter Number to reverse: ");
	scanf("%d", &n);

	rev = reverse(n);
	printf("Reversed Number is %d\n", rev);
	return 0; 
}
