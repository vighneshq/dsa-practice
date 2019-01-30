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
void dfs(Node*, int, int, bool*);

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

	bool* reachable = calloc(N, sizeof(bool));
	bool exists = false;

	for(int i=0;i<N;i++)
	{
		bool* visited = calloc(N, sizeof(bool));
		dfs(nodes, N, i, visited);
		int count = 0;
		for(int i=0;i<N;i++)
		{
			count += visited[i];
		}
		if(count == N)
		{
			reachable[i] = true;
			exists = true;
		}
	}

	if(exists)
	{
		printf("Yes.\n");
		for(int i=0;i<N;i++)
		{
			if(reachable[i])
			{
				printf("%d ", i+1);
			}
		}
		printf("\n");
	}	
	else
	{
		printf("No such vertex exists.\n");
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

void dfs(Node* nodes, int N, int curr, bool* visited)
{
	if(visited[curr])
	{
		return;
	}

	visited[curr] = true;

	for(int i=0;i<nodes[curr].outDeg;i++)
	{
		int adj = nodes[curr].neighbours[i];
		if(!visited[adj])
		{
			dfs(nodes, N, adj, visited);
		}
	}
}
