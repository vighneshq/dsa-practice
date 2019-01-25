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
void createGraph(int*[], int*[], int);
void BFS(int**, int**, int, int);
void printPathsDFS(int**, int, int, int, int[], int, int**);	


int main()
{
	int N;
	scanf("%d", &N);
	
	int *adj[N], *dist[N];
	createGraph(adj, dist, N);
	int E;
	scanf("%d", &E);
	for(int i=0;i<E;i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		adj[x-1][y-1] = adj[y-1][x-1] = 1;
	}

	for(int i=0;i<N;i++)
	{
		BFS(adj, dist, N, i);
	}

	int diam = -1;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			diam = (diam>dist[i][j])?diam:dist[i][j];
		}
	}

	printf("Diameter - %d\n", diam);
	int *path = calloc(N, sizeof(int));
	for(int i=0;i<N;i++)
	{
		printPathsDFS(adj, N, i, diam+1, path, 0, dist);
	}	
}

void createGraph(int* adj[], int*dist[], int N)
{
	for(int i=0;i<N;i++)
	{
		adj[i] = calloc(N, sizeof(int));
		dist[i] = calloc(N, sizeof(int));
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

void BFS(int** adj, int** dist, int N, int source)
{
	bool visited[N];
	for(int i=0;i<N;i++)
	{
		dist[source][i] = -1;
		visited[i] = false;
	}

	Queue queue = createQueue(N);
	enqueue(&queue, source);
	dist[source][source] = 0;
	visited[source] = true;
	while(!isEmpty(&queue))
	{
		int curr = dequeue(&queue);
		for(int i=0;i<N;i++)
		{
			if(adj[curr][i] == 1 && visited[i] == false)
			{
				visited[i] = true;
				dist[source][i] = dist[source][curr] + 1;
				enqueue(&queue, i);
			}
		}
	}
}

void printPathsDFS(int **adj, int N, int curr, int k, int path[], int c, int** dist)
{
	int p[N];
	for(int i=0;i<c;i++)
	{
		p[i] = path[i];	
	}
	p[c++] = curr;
	k--;
	if(k <= 0)
	{
		int start = p[0];
		int end = p[c-1];
		// if(dist[start][end] >= c-1)
		// {
			for(int i=0;i<c;i++)
			{
				printf("%d ", p[i]+1);
			}
			printf("\n");
		// }
		return;
	}
	for(int i=0;i<N;i++)
	{
		if(adj[curr][i] == 1)
		{
			int visited = false;
			for(int j=0;j<c;j++)
			{
				if(p[j] == i)
				{
					visited = true;
					break;
				}
			}
			if(!visited)
			{
				printPathsDFS(adj,N, i, k, p, c, dist);			
			}
		}
	}
}