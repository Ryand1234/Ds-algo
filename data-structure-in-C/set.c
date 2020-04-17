#include<cstdio>
#include<cstdlib>

struct Set
{
	int value;
	struct Set *node;
};

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


int main()
{
	int t,n;
	Set *set = init();
	do{
		printf("Enter your choice (0:Exit | 1:Insert | 2:Remove | 3:Size | 4:Print)? ");
		scanf("%d",&t);
		switch(t)
		{
			case 0: break;
			case 1: printf("Enter Value: ");
				scanf("%d",&n);
				if(exist(set, n))
					insert(set, n);
				else
					printf("Value already exists\n");
				break;
			case 2: printf("Enter Value to remove: ");
				scanf("%d",&n);
				if(set->value == n)
				{
					set = set->node;
				}				
				else
					remove(set, n);
				break;
			case 3: n = size(set);
				printf("Size is %d\n",n);
				break;
			case 4: print(set);
				printf("\n");
				break;
			default: printf("Wrong Choice\n");
		}
	}while(t != 0);
	return 0;
}
