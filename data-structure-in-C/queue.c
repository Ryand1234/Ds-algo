#include<cstdio>
#include<cstdlib>

struct Queue {
	
	int value;
	struct Queue *front;
};

Queue *init()
{
	Queue *queue = (Queue*)malloc(sizeof(Queue));
	queue->value = 0;
	queue->front = NULL;
	return queue;
}

void push(Queue *queue, int n)
{
	if(queue->front == NULL)
	{
		queue->value = n;
		queue->front = init();
	}
	else
		push(queue->front, n);
}

int size(Queue *queue)
{
	if(queue->front == NULL)
		return 0;

	return 1 + size(queue->front);
}


void print(Queue *queue)
{
	if(queue->front == NULL)
		return;
	else{
		printf("%d->",queue->value);
		print(queue->front);
	}
}


Queue *pop(Queue *queue)
{
	printf("Poped Value is %d\n", queue->value);
	return queue->front;
}


int main()
{
	int t,n,s;
	Queue *queue = init();
	do {
		printf("Enter your choice (0: Exit | 1:Insert | 2:Pop | 3:Print | 4:Size)? ");
		scanf("%d",&t);
		switch(t)
		{
			case 0: break;
			case 1: printf("Enter value: ");
				scanf("%d",&n);
				push(queue, n);
				break;
			case 2: queue = pop(queue);
				break;
			case 3: print(queue);
				printf("\n");
				break;
			case 4: s = size(queue);
				printf("Size is %d\n",s);
				break;
			default: printf("Wrong Choice\n");
		}
	}while(t != 0);

	return 0;
}
