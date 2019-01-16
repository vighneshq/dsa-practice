#include<stdio.h>

int main()
{
	int n;
	scanf("%d", &n);

	int matrix[n][n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d", &matrix[i][j]);
		}
	}

	int rowMin[n], colMax[n];

	for(int i=0;i<n;i++)
	{
		int min = matrix[i][0];
		int max = matrix[0][i];

		for(int j=0;j<n;j++)
		{
			if(min > matrix[i][j])
			{
				min = matrix[i][j];
			}
			if(max < matrix[j][i])
			{
				max = matrix[j][i];
			}
		}

		rowMin[i] = min;
		colMax[i] = max;
	}

	int saddle;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(matrix[i][j] == rowMin[i] && matrix[i][j] == colMax[j])
			{
				printf("Saddle point %d found at cell (%d, %d).\n", matrix[i][j], i, j);
				saddle = 1;
			}
		}
	}

	if(!saddle)
	{
		printf("No saddle points found.\n");
	}

	return 0;
}