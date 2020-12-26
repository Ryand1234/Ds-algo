#include<stdio.h>
#include<stdlib.h>


typedef struct Stack {
	
	int value;
	struct Stack *index;
} Stack;

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

