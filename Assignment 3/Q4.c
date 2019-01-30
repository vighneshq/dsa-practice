#include<stdio.h>
#include<stdlib.h>

// Struct for graph nodes
typedef struct node
{
	int* neighbours;
	int deg;
} Node;

// Misc
void fillArray(int[], int, int);

// Functions for Graph
void createGraph(Node*, int);
void addEdge(Node*, int, int);
void dfs(Node*, int, int, int, int[], int*);
int subTreeCount(int, int[], int);

int main()
{
	int N;
	scanf("%d", &N);

	Node* nodes = calloc(N, sizeof(Node));
	createGraph(nodes, N);

	for(int i=0;i<N-1;i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		addEdge(nodes, a-1, b-1);
	}

	int x, y;
	scanf("%d %d", &x, &y);
	x--;
	y--;

	int visited[N];
	int subtree[N];

	fillArray(subtree, N, -1);
	fillArray(visited, N, 0);
	dfs(nodes, N, y, x, subtree, visited);
	int xTree = subTreeCount(x, subtree, N);

	fillArray(subtree, N, -1);
	fillArray(visited, N, 0);
	dfs(nodes, N, x, y, subtree, visited);
	int yTree = subTreeCount(y, subtree, N);

	printf("%d\n", N*(N-1) - xTree*yTree);
	return 0;
}

void createGraph(Node* nodes, int N)
{
	for(int i=0;i<N;i++)
	{
		nodes[i].neighbours = calloc(N, sizeof(int));
		nodes[i].deg = 0;
	}
}

void addEdge(Node* nodes, int x, int y)
{
	nodes[x].neighbours[nodes[x].deg++] = y;
	nodes[y].neighbours[nodes[y].deg++] = x;
}

void fillArray(int arr[], int N, int val)
{
	for(int i=0;i<N;i++)
	{
		arr[i] = val;
	}
}

void dfs(Node* nodes, int N, int curr, int other, int subtree[], int* visited)
{
	if(visited[curr])
	{
		return;
	}

	visited[curr] = 1;
	if(curr == other)
	{
		subtree[curr] = other;
	}
	
	for(int i=0;i<nodes[curr].deg;i++)
	{
		int adj = nodes[curr].neighbours[i];
		if(!visited[adj])
		{
			subtree[adj] = subtree[curr];
			dfs(nodes, N, adj, other, subtree, visited);
		}
	}
}

int subTreeCount(int node, int subtree[], int N)
{
	int count = 0;
	for(int i=0;i<N;i++)
	{
		if(subtree[i] == node)
		{
			count++;
		}
	}

	return count;
}