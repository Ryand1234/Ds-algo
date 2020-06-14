#include<stdio.h>
#define ll long long int

int main()
{
	ll a, b, sum;
	printf("A: ");
	scanf("%lld",&a);
	printf("B: ");
	scanf("%lld",&b);
	printf("A: %lld, B: %lld\n",a,b);
	sum = a + b;
	printf("Sum: %lld\n",sum);
	return 0; 
}
