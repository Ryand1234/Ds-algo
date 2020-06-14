#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a, b, sum;
	float avg;
	printf("A: ");
	scanf("%d",&a);
	printf("B: ");
	scanf("%d",&b);
	printf("A: %d, B: %d\n",a,b);
	sum = a + b;
	avg = sum/2.0;
	printf("Sum: %d\n",sum);
	printf("Average: %f\n",avg);
	return 0; 
}
