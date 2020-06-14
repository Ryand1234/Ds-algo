#include<stdio.h>

int exp_rec(int a, int b)
{
	if(b == 1)
		return a;

	return a*exp_rec(a, b-1);
}
int main()
{
	int a, b;
	printf("Enter Base: ");
	scanf("%d", &a);
	printf("Enter Exponent: ");
	scanf("%d", &b);
	printf("%d^%d is %d\n", a, b, exp_rec(a, b));
	return 0; 
}
