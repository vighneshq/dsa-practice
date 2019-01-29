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

typedef struct edge
{
	int a, b;
} Edge;

// Functions for implementing queue
Queue createQueue(unsigned int);
bool isFull(Queue*);
bool isEmpty(Queue*);
void enqueue(Queue*, int);
int dequeue(Queue*);

// Functions for graph
void createGraph(int*[], int);
bool isAdjacent(Edge[], int, int);
bool BFS(int**, int, int, bool[], int[], int);
bool cutVertex(int**, int, int, int);
void printComponent(int**, int, int[], int);

int main()
{
	
	int N;
	scanf("%d", &N);
	
	int E;
	scanf("%d", &E);
	Edge edges[E];
	for(int i=0;i<E;i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		edges[i].a = x-1;
		edges[i].b = y-1;
	}

	int *edgeGraph[E];
	createGraph(edgeGraph, E);
	for(int i=0;i<E;i++)
	{
		for(int j=i+1;j<E;j++)
		{
			if(isAdjacent(edges, i, j))
			{
				edgeGraph[i][j] = edgeGraph[j][i] = 1;
			}
		}
	}

	int k = 0;
	bool *visited = calloc(E, sizeof(bool));
	int *component = calloc(E, sizeof(int));

	for(int i=0;i<E;i++)
	{
		if(!visited[i])
		{
			k++;
			BFS(edgeGraph, E, i, visited, component, k);
		}
	}

	bool done = false;
	for(int i=0;i<E;i++)
	{
		done = cutVertex(edgeGraph, i, E, k);
		if(done)
		{
			break;
		}
	}
	if(!done)
	{
		printf("No cut-vertex found.\n");
	}
	return 0;
}

void createGraph(int* arr[], int N)
{
	for(int i=0;i<N;i++)
	{
		arr[i] = calloc(N, sizeof(int));
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

bool isAdjacent(Edge edges[], int i, int j)
{
	return (edges[i].a == edges[j].a || edges[i].a == edges[j].b || edges[i].b  == edges[j].a 
			|| edges[i].b == edges[j].b);
}

bool BFS(int** adj, int N, int source, bool visited[], int component[], int c)
{
	Queue queue = createQueue(N);
	enqueue(&queue, source);
	visited[source] = true;
	while(!isEmpty(&queue))
	{
		int curr = dequeue(&queue);
		component[curr] = c;
		for(int i=0;i<N;i++)
		{
			if(adj[curr][i] == 1)
			{
				if(visited[i] == false)
				{
					visited[i] = true;
					enqueue(&queue, i);
				}
			}
		}
	}
}

bool cutVertex(int** edgeGraph, int cutV, int E, int k)
{
	bool *visited = calloc(E, sizeof(bool));
	int *component = calloc(E, sizeof(int));

	int *temp[E];
	createGraph(temp, E);
	for(int i=0;i<E;i++)
	{
		for(int j=0;j<E;j++)
		{
			temp[i][j] = edgeGraph[i][j];
		}
	}
	for(int i=0;i<E;i++)
	{
		temp[cutV][i] = temp[i][cutV] = 0;
	}

	int c = 0;
	for(int i=0;i<E;i++)
	{
		if(i != cutV && !visited[i])
		{
			c++;
			BFS(temp, E, i, visited, component, c);
		}
	}
	if(c > k)
	{
		printf("Cut Vertex - %d\n", cutV+1);
		printComponent(temp, E, component, c);
		return true;
	}
	return false;
}

void printComponent(int**adj, int N, int component[], int c)
{
	for(int i=1;i<=c;i++)
	{
		printf("Component %d\n  ", i);
		for(int j=0;j<N;j++)
		{
			if(component[j] == i)
			{
				printf("%d ", j+1);
			}
		}
		printf("\n");
		for(int j=0;j<N;j++)
		{
			if(component[j] == i)
			{
				printf("%d ", j+1);
				for(int k=0;k<N;k++)
				{
					if(component[k] == i)
					{
						printf("%d ", adj[j][k]);
					}
				}
				printf("\n");
			}
		}
	}
}