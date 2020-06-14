#include<stdio.h>

int main()
{
	int p, r, t, si;
	printf("Enter Principal: ");
	scanf("%d", &p);
	printf("Enter Rate: ");
	scanf("%d", &r);
	printf("Enter Time: ");
	scanf("%d", &t);

	si = (p*r*t)/100;

	printf("Simple Intrest is %d\n", si);
	return 0; 
}
