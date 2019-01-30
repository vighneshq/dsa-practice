#include<stdio.h>
#include<stdlib.h>

// Enum for custom bool
typedef enum {false, true} bool;

// Struct for graph nodes
typedef struct node
{
	int* neighbours;
	int outDeg;
} Node;

// Functions for Graph
void createGraph(Node*, int);
void addEdge(Node*, int, int);

int main()
{
	int N, x, y;
	scanf("%d %d %d", &N, &x, &y);

	Node* nodes = calloc(N, sizeof(Node));
	createGraph(nodes, N);

	for(int i=0;i<N-1;i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		addEdge(nodes, a-1, b-1);
	}

	
	return 0;
}

void createGraph(Node* nodes, int N)
{
	for(int i=0;i<N;i++)
	{
		nodes[i].neighbours = calloc(N, sizeof(int));
		nodes[i].outDeg = 0;
	}
}

void addEdge(Node* nodes, int x, int y)
{
	nodes[x].neighbours[nodes[x].outDeg++] = y;
	nodes[y].neighbours[nodes[y].outDeg++] = x;
}
