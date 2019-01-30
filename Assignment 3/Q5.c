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

}