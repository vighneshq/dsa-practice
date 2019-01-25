#include<stdlib.h>
#include<stdio.h>

// Enum for custom bool
typedef enum {false, true} bool;

// Queue definition
typedef struct queue
{
	int front, end, size;
	unsigned int capacity;
	int* array;
} Queue;

// Functions for implementing queue
Queue createQueue(unsigned int);
bool isFull(Queue*);
bool isEmpty(Queue*);
void enqueue(Queue*, int);
int dequeue(Queue*);

// Functions for graph
void createGraph(int*[], int);

int main()
{
	
	int N;
	scanf("%d", &N);
	
	int *adj[N];
	createGraph(adj, N);
	int E;
	scanf("%d", &E);
	for(int i=0;i<E;i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		adj[x-1][y-1] = adj[y-1][x-1] = 1;
	}

	int *edgeGraph[E];
	createGraph(edgeGraph, E);
	return 0;
}

void createGraph(int* adj[], int N)
{
	for(int i=0;i<N;i++)
	{
		adj[i] = calloc(N, sizeof(int));
	}
}

Queue createQueue(unsigned int capacity)
{
	Queue* queue = (Queue*) malloc(sizeof(Queue));
	queue->capacity = capacity;
	queue->size = 0;
	queue->front = 0;
	queue->end = capacity - 1;
	queue->array = (int*) malloc(capacity*sizeof(int));
	return *queue;
} 

bool isFull(Queue* queue)
{
	return (queue->size == queue->capacity)?true:false;
}

bool isEmpty(Queue* queue)
{
	return (queue->size == 0)?true:false;
}

void enqueue(Queue* queue, int elem)
{
	if(isFull(queue))
	{
		return;
	}
	queue->end = (queue->end + 1)%queue->capacity;
	queue->array[queue->end] = elem;	
	queue->size++;	
}

int dequeue(Queue* queue)
{
	if(isEmpty(queue))
	{
		return -1;
	}
	int elem = queue->array[queue->front];
	queue->front = (queue->front+1)%queue->capacity;
	queue->size--;
	return elem;
}