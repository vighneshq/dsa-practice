#include<stdlib.h>
#include<stdio.h>
#define INF 100000

// Enum for custom bool
typedef enum {false, true} bool;

// Functions for graph
void createGraph(int*[], int*[], int);
void FloydWarshall(int*[], int);
void printCycleDFS(int**, int, int, int, bool[], int[], int, int);

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
		int x, y, w;
		scanf("%d %d %d", &x, &y, &w);
		adj[x-1][y-1] = w;
		dist[x-1][y-1] = w;
	}

	int min = INF;

	FloydWarshall(dist, N);

	for(int i=0;i<N;i++)
	{
		for(int j=i+1;j<N;j++)
		{
			int temp = dist[i][j] + dist[j][i];
			min = (min<temp)?min:temp;
		}
	}
	printf("%d\n", min);

	bool* visited = calloc(N, sizeof(bool));
	int* path = calloc(N+1, sizeof(int));
	for(int i=0;i<N;i++)
	{
		printCycleDFS(adj, N, i, i, visited, path, 0, min);
	}
	// (int** adj, int N, int source, int curr, bool visited[], int path[], int c, int min)
}

void createGraph(int* adj[], int*dist[], int N)
{
	for(int i=0;i<N;i++)
	{
		adj[i] = calloc(N, sizeof(int));
		dist[i] = calloc(N, sizeof(int));
	}

	for(int i=0;i<N;i++)
	{
		for(int j=i+1;j<N;j++)
		{
			adj[i][j] = adj[j][i] = INF;
			dist[i][j] = dist[j][i] = INF;
		}
	}
}

void FloydWarshall(int* dist[], int N)
{
	for(int k=0;k<N;k++)
	{
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				if (dist[i][k] + dist[k][j] < dist[i][j])
				{
                    dist[i][j] = dist[i][k] + dist[k][j]; 
				} 
			}
		}
	}
}

void printCycleDFS(int** adj, int N, int source, int curr, bool visited[], int path[], int c, int min)
{
	bool vis[N+1];
	int p[N+1];
	for(int i=0;i<N;i++)
	{
		vis[i] = visited[i];
		p[i] = path[i];
	}
	p[c++] = curr;
	if(curr == source && c != 1)
	{	
		
		int sum = 0;
		for(int i=0;i<c-1;i++)
		{
			sum+= adj[p[i]][p[i+1]];
		}
		if(sum == min)
		{
			for(int i=0;i<c;i++)
			{
				printf("%d ", p[i]+1);
			}
			printf("\n");
		}
		return;
	}
	for(int i=0;i<N;i++)
	{
		if(adj[curr][i] > 0 && adj[curr][i] != INF && vis[i] == false)
		{
			vis[i] = true;
			printCycleDFS(adj, N, source, i, vis, p, c, min);
		}
	}
	
}