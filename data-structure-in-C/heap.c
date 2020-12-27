#include <stdio.h>
#include <stdlib.h>
#define MAX 50

typedef struct Heap{
	int n;
	int q[MAX];
} Heap;

Heap *init()
{
	Heap *heap = (Heap*)malloc(sizeof(Heap));
	heap->n = 0;
	return heap;
}

int parent(int n)
{
	if(n == 1)
		return -1;
	return n/2;
}

void swap(Heap *heap, int p, int q)
{
	int k;
	k = heap->q[p];
	heap->q[p] = heap->q[q];
	heap->q[q] = k;
}

void heapify(Heap *heap, int n)
{
	if(parent(n) == -1)
		return;
	if(heap->q[parent(n)] > heap->q[n])
	{
		swap(heap, n, parent(n));
		heapify(heap, parent(n));
	}
}

void make_heap(Heap *heap, int k)
{
	if(heap->n == MAX)
	{
		printf("Heap Full!!!!!!!!!!!\n");
	} else {
		heap->n = heap->n + 1;
		heap->q[heap->n] = k;
		heapify(heap, heap->n);
	}
}

void print_heap(Heap *heap)
{
	for (int i = 0; i < heap->n; ++i)
	{
		printf("%d->", heap->q[i]);
	}
	printf("\n");
}

int main()
{
	Heap *heap = init();
	int n = 10;
	int A[] = {21, 65, 48, 23, 15, 689, 12, 546, 321, 57};
	for (int i = 0; i < n; i++)
	{
		make_heap(heap, A[i]);
	}
	print_heap(heap);
	return 0;
}