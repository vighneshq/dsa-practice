#include<stdlib.h>
#include<stdio.h>

// Enum for custom bool
typedef enum {false, true} bool;

// Enum for graph partition
typedef enum {NONE, WHITE, BLACK} color;

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
bool BFS(int**, int, int, color[], bool[]);

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
		int u, v;
		scanf("%d, %d", &u, &v);
		adj[u-1][v-1] = adj[v-1][u-1] = 1;
	}

	bool* visited = calloc(N, sizeof(bool));
	color* partition = calloc(N, sizeof(color));

	bool isBipartite = 1;
	for(int i=0;i<N;i++)
	{
		if(!visited[i])
		{
			isBipartite&= BFS(adj, N, i, partition, visited);
		}
	}
	if(isBipartite)
	{
		printf("Bipartite.\n");
	}
	else
	{
		printf("Not bipartite.\n");
	}
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

bool BFS(int** adj, int N, int source, color c[], bool visited[])
{
	Queue queue = createQueue(N);
	enqueue(&queue, source);
	visited[source] = true;
	c[source] = BLACK;
	while(!isEmpty(&queue))
	{
		int curr = dequeue(&queue);
		for(int i=0;i<N;i++)
		{
			if(adj[curr][i] == 1)
			{
				if(visited[i] == false)
				{
					visited[i] = true;
					enqueue(&queue, i);
					c[i] = (c[curr] == BLACK)?WHITE:BLACK;
				}
				else if(c[curr] == c[i])
				{
					return false;
				}

			}
		}
	}
	return true;
}