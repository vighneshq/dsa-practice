#include<stdio.h>

int main()
{
	int N;
	scanf("%d", &N);

	int matrix[N][N];
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			scanf("%d", &matrix[i][j]);				
		}
	}

	// Extremely inefficient bruteforce solution
	int sum = matrix[0][0];
	for(int k=N;k>=1;k--)
	{
		for(int i=0;i<=N-k;i++)
		{
			for(int j=0;j<=N-k;j++)
			{
				int s = 0;
				for(int x=0;x<k;x++)
				{
					for(int y=0;y<k;y++)
					{
						s+=matrix[i+x][j+y];
					}
				}
				sum = (sum>s)?sum:s;
			}
		}
	}
	printf("%d\n", sum);
	return 0;
}