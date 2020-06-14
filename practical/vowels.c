#include<stdio.h>
#include<string.h>
#define MAX 20

void check(char s[])
{
	char vowel[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

	int len = strlen(s) - 1;
	int i, j, Cvowel = 0;
	
	for(i = 0; i < len; i++)
	{
		for(j = 0; j < 10; j++)
		{
			if(s[i] == vowel[j])
			{
				Cvowel += 1;
				break;
			}
		}
	}

	printf("Total Vowel is %d\n", Cvowel);
}

int main()
{
	char s[MAX];
	printf("Enter the String: ");
	fgets(s, MAX, stdin);
	check(s);
	return 0; 
}
