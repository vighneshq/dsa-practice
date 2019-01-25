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
void BFS(int**, int, int, int[], bool[]);

int main()
{
	int N;
	scanf("%d", &N);

	int *adj[N];
	createGraph(adj, N);
	for(int i=0;i<N-1;i++)
	{
		int u, v;
		scanf("%d, %d", &u, &v);
		adj[u-1][v-1] = adj[v-1][u-1] = 1;
	}

	int M;
	scanf("%d", &M);
	int* college = (int*) calloc(N, sizeof(int));
	int min = N;
	for(int i=0;i<M;i++)
	{
		int x;
		scanf("%d", &x);
		college[x-1] = 1;
		if(x < min)
		{
			min = x;
		}
	}

	int* dist = (int*) malloc(N*sizeof(int));
	bool* visited = (bool*) calloc(N, sizeof(bool));	

	BFS(adj, N, 0, dist, visited);
	
	min--;
	for(int i=1;i<N;i++)
	{
		if(college[i])
		{
			if(dist[i] != - 1 && dist[i] < dist[min])
			{
				min = i;
			}
		}
	}
	printf("%d\n", min+1);
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

void BFS(int** adj, int N, int source, int dist[], bool visited[])
{
	for(int i=0;i<N;i++)
	{
		dist[i] = -1;
	}

	Queue queue = createQueue(N);
	enqueue(&queue, source);
	dist[source] = 0;
	visited[source] = true;
	while(!isEmpty(&queue))
	{
		int curr = dequeue(&queue);
		for(int i=0;i<N;i++)
		{
			if(adj[curr][i] == 1 && visited[i] == false)
			{
				visited[i] = true;
				dist[i] = dist[curr] + 1;
				enqueue(&queue, i);
			}
		}
	}
}