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
void dfs(Node*, int, int, int, bool*, bool**);

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);

	Node* nodes = calloc(N, sizeof(Node));
	createGraph(nodes, N);

	for(int i=0;i<M;i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		addEdge(nodes, a-1, b-1);
	}

	bool** reachable = calloc(N, sizeof(bool*));
	for(int i=0;i<N;i++)
	{
		reachable[i] = calloc(N, sizeof(bool));
	}

	for(int i=0;i<N;i++)
	{
		bool* visited = calloc(N, sizeof(bool));
		dfs(nodes, N, i, i, visited, reachable);
	}

	int t;
	scanf("%d", &t);
	while(t--)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		if(reachable[x-1][y-1])
		{
			printf("Yes.\n");
		}
		else
		{
			printf("No.\n");
		}
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
}

void dfs(Node* nodes, int N, int source, int curr, bool* visited, bool** reachable)
{
	if(visited[curr])
	{
		return;
	}

	visited[curr] = true;
	reachable[source][curr] = true;

	for(int i=0;i<nodes[curr].outDeg;i++)
	{
		int adj = nodes[curr].neighbours[i];
		if(!visited[adj])
		{
			dfs(nodes, N, source, adj, visited, reachable);
		}
	}
}
