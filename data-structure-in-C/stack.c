#include<cstdio>
#include<cstdlib>


struct Stack {
	
	int value;
	struct Stack *index;
};

Stack *init()
{
	Stack *stack = (Stack*)malloc(sizeof(Stack));
	stack->value = 0;
	stack->index = NULL;
	return stack;
}

void print(Stack *stack)
{
	if(stack->index == NULL)
	{
		return;
	}
	else
	{
		printf("%d->",stack->value);
		print(stack->index);
	}
}



void push(Stack *stack, int n)
{
	if(stack->index != NULL)
		push(stack->index, n);
	else
	{
		stack->value = n;
		stack->index = init();
	}
}


void pop(Stack *stack)
{
	if(stack->index == NULL)
	{
		printf("Stack is empty\n");
		return;
	}
	if(stack->index->index == NULL)
	{
		printf("Value Poped is %d\n",stack->value);
		stack->index = NULL;
	}
	else
	{
		pop(stack->index);
	}
}

int main()
{
	int t,n;
	Stack *stack = init();
	do{
		printf("Enter your choice (0:Exit | 1:Push | 2:Pop | 3:Print)? ");
		scanf("%d",&t);
		switch(t)
		{
			case 0: break;
			case 1: printf("Enter Value: ");
				scanf("%d",&n);
				push(stack, n);
				break;
			case 2: pop(stack);
				break;
			case 3: print(stack);
				printf("\n");
				break;
			default: printf("Wrong Choice\n");
		}
	}while(t != 0);

	return 0;
}
