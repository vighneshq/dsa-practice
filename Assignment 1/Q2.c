#include<stdio.h>

void printMatrix(int);

int main()
{
	int n;
	scanf("%d", &n);
	
	printMatrix(n);
}

void printMatrix(int n)
{
	int matrix[n][n];
	int elem = n*n;
	
	int min = 0;
	int max = n - 1;
	while(elem > 0)
	{
		int row, col;
		row = col = max;
		while(col > min)
		{
			matrix[row][col--] = elem--;
		}	
		while(row > min)
		{
			matrix[row--][col] = elem--;
		}
		while(col < max)
		{
			matrix[row][col++] = elem--;
		}
		while(row < max)
		{
			matrix[row++][col] = elem--;
		}
		if(min == max)
		{
			matrix[row][col] = elem--;
		}
		min++;
		max--;
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}
