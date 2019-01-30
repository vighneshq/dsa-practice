#include<stdio.h>
#include<stdlib.h>

// Function for matrix bounds
int canBeIndexed(int, int, int);

// Functions for Graph
void createMatrix(int*[], int);
void dfs(int**, int, int, int, int*, int*[]);

int main()
{
	int N;
	scanf("%d", &N);

	int *matrix[N];
	createMatrix(matrix, N);
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			scanf("%d", &matrix[i][j]);
		}
	}

	int* visited[N];
	createMatrix(visited, N);
	int max = 0;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			int count = 0;
			if(!visited[i][j] && matrix[i][j] == 1)
			{
				dfs(matrix, N, i, j, &count, visited);
			}
			max = (max>count)?max:count;
		}
	}
	printf("%d\n", max);
	return 0;
}

int canBeIndexed(int row, int col, int N)
{
	return (row >= 0 && row <= N - 1 && col >= 0 && col <= N - 1);
}

void createMatrix(int** visited, int N)
{
	*visited = calloc(N, sizeof(int*));
	for(int i=0;i<N;i++)
	{
		visited[i] = calloc(N, sizeof(int));
	}
}

void dfs(int** matrix, int N, int row, int col, int* count, int* visited[])
{
	if(visited[row][col])
	{
		return;
	}

	visited[row][col] = 1;
	(*count)++;
	for(int i=-1;i<=1;i++)
	{
		for(int j=-1;j<=1;j++)
		{
			int newRow = row + i;
			int newCol = col + j;
			if(canBeIndexed(newRow, newCol, N) && matrix[newRow][newCol] == 1 && !visited[newRow][newCol])
			{
				dfs(matrix, N, newRow, newCol, count, visited);
			}
		}
	}
}
