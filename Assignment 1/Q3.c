#include<stdio.h>

void printMatrix(int [], int);
void fillPrimes(int[], int);

int main()
{
	int n;
	scanf("%d", &n);
	
	int primes[n*n];
	fillPrimes(primes, n);
	printMatrix(primes, n);
}

void fillPrimes(int primes[], int n)
{
	primes[0] = 2;
	int count = 1;
	int p = 3;
	while(count < n*n)
	{
		int isPrime = 1;
		for(int i=2;i*i<=p;i++)
		{
			if(p%i == 0)
			{
				isPrime = 0;
				break;
			}
		}

		if(isPrime)
		{
			primes[count++] = p;
		}
		p++;
	}
}

void printMatrix(int primes[], int n)
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
			matrix[row][col--] = primes[--elem];
		}	
		while(row > min)
		{
			matrix[row--][col] = primes[--elem];
		}
		while(col < max)
		{
			matrix[row][col++] = primes[--elem];
		}
		while(row < max)
		{
			matrix[row++][col] = primes[--elem];			
		}
		if(min == max)
		{
			matrix[row][col] = primes[--elem];
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
