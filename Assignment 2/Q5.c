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
void createGraph(int*[], int [], int, int);
void BFS(int**, int, int, bool[], int[], int);

int main()
{
	int N;
	scanf("%d", &N);

	int *adj[N];
	int factor[N];
	for(int i=0;i<N;i++)
	{
		scanf("%d", &factor[i]);
	}
	
	int delta;
	scanf("%d", &delta);
	createGraph(adj, factor, N, delta);


	printf("Adjacency Matrix\n  ");
	for(int i=0;i<N;i++)
	{
		printf("%d ", i+1);
	}
	printf("\n");
	for(int i=0;i<N;i++)
	{
		printf("%d ", i+1);
		for(int j=0;j<N;j++)
		{
			printf("%d ", adj[i][j]);
		}
		printf("\n");
	}

	bool* visited = calloc(N, sizeof(bool));
	int component[N];
	int c = 0;

	// Mark each vertex with component
	for(int i=0;i<N;i++)
	{
		if(!visited[i])
		{
			c++;
			BFS(adj, N, i, visited, component, c);
		}
	}

	// Print adjacency matrix for individual components
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

	return 0;
}

void createGraph(int* adj[], int factor[], int N, int delta)
{
	for(int i=0;i<N;i++)
	{
		adj[i] = calloc(N, sizeof(int));
	}

	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(abs(factor[i] - factor[j]) >= delta)
			{
				adj[i][j] = 1;
			}
		}
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

void BFS(int** adj, int N, int source, bool visited[], int component[], int c)
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
