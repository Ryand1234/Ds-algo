#include<stdio.h>
#include<stdlib.h>

typedef struct Deque {

	int value;
	struct Deque *back;

} Deque;

Deque *init()
{

	Deque *deque = (Deque*)malloc(sizeof(Deque));
	deque->value = 0;
	deque->back = NULL;
	return deque;

}

Deque *insert_front(Deque *deque, int n)
{

	if(deque->back != NULL)
	{

		Deque *new_queue = init();
		new_queue->value = n;
		new_queue->back = deque;
		deque = new_queue;

	}
	else
	{

		deque->value = n;
		deque->back = init();

	}

	return deque;

}

void print(Deque *deque)
{

	if(deque->back == NULL)
	{

		return;	

	}
	else{

		printf("%d->",deque->value);
		print(deque->back);

	}

}

Deque *pop_front(Deque *deque)
{
	Deque *new_queue = (Deque*)malloc(sizeof(Deque));

	if(deque->back == NULL)
	{

		printf("Deque is empth\n");
		return deque;

	}

	printf("Poped Value is %d\n",deque->value);
	new_queue = deque->back;

	return new_queue;

}

void pop_back(Deque *deque)
{
	
	if(deque->back == NULL)
	{
		
		printf("Deque is empty\n");
		return;

	}
	else
	{

		if(deque->back->back->back == NULL)
		{

			printf("Poped Value is %d\n",deque->back->value);
			deque->back = init();

		}
		else
		{

			if(deque->back->back == NULL)
			{

				deque->value = 0;
				deque->back = NULL;

			}
			else
			{

				pop_back(deque->back);

			}

		}

	}
}

void insert_back(Deque *deque, int n)
{
	
	if(deque->back == NULL)
	{

		deque->value = n;
		deque->back = init();

	}
	else
	{

		insert_back(deque->back, n);

	}

//	return deque;
}


int size(Deque *deque)
{

	if(deque->back == NULL)
		return 0;

	return 1 + size(deque->back);

}
