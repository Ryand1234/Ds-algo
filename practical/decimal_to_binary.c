#include<stdio.h>
#include<string.h>

int power(int n)
{
	int power = 1;

	for(int i = 0; i < n; i++)
		power *= 2;

	return power;
}

void reverse(char n[])
{
	for(int i = strlen(n)-1; i >= 0; i--)
		printf("%c",n[i]);
	printf("\n");
}

void binary(int n)
{

	char bin[] = "";
	int t = 0;
	while(n)
	{
		t++;
		if(n%2 == 1)
			strcat(bin, "1");
		else
			strcat(bin, "0");
		n /= 2;
	}

	bin[t] = '\0';

	reverse(bin);

}

void decimal(int n)
{
	printf("N: %d\n",n);
	int t=0;
	int decimal=0;
	while(n)
	{

		printf("N: %d\n",n);
		if((n%10 != 1 && n%10 != 0))
		{
			printf("Enter Valid Binary Number\n");
			return ;
		}
		if(n%10 == 1)
		{
			decimal += power(t);
		}

		printf("DECIMAL: %d\n",decimal);
		n /= 10;
		t++;
	}

	printf("Decimal Equivalent is %d\n", decimal);
}

int main()
{
	int n, k;
	printf("Converter only positive interger are allowed\n");
	do{
		printf("1. Binary to Decimal\n");
		printf("2. Decimal to Binary\n");
		printf("3. Exit\n");
		scanf("%d", &k);

		switch(k)
		{
			case 1: printf("Enter Binary Number: ");
				scanf("%d", &n);
				printf("N: %d\n",n);
				decimal(n);
				break;
			case 2: printf("Enter Decimal Number: ");
				scanf("%d", &n);
				binary(n);
				break;
			case 3: printf("Exit\n");
				break;
			default: printf("Wrong Choice\n");
		}
	}while(k != 3);
	return 0; 
}
