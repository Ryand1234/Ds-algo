#include<stdio.h>
#include<stdlib.h>

typedef struct Set
{
	int value;
	struct Set *node;
} Set;

Set *init()
{
	Set *set = (Set*)malloc(sizeof(Set));
	set->value = 0;
	set->node = NULL;
	return set;
}

bool exist(Set *set, int n)
{
	if(set->node == NULL)
		return true;
	else
	{
		if(set->value != n)
			return exist(set->node, n);
		else
		{
			return false;
		}
	}
}

void insert(Set *set, int n)
{
	if(set->node == NULL)
	{
		set->value = n;
		set->node = init();
	}
	else
	{
		insert(set->node, n);
	}

}

int size(Set *set)
{
	if(set->node == NULL)
		return 0;
	
	return 1 + size(set->node);
}

void print(Set *set)
{
	if(set->node != NULL)
	{
		printf("%d->", set->value);
		print(set->node);
	}
	else
	{
		printf("Set Empty");
		return;
	}
}

void remove(Set *set, int n)
{
	if(set->node == NULL)
	{
		printf("Set Empty\n");
		return;
	}
	else
	{
		if(set->node->node == NULL)
		{
			if(set->value != n)
				printf("Value doesnt exist\n");
			else
				set = init();
		}	
		else
		{
			if(set->node->value != n)
				remove(set->node, n);
			else
			{
				printf("Value removed \n");
				set->node = set->node->node;
			}
		}
	}
}