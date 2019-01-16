#include<stdio.h>

int min(int, int);
int max(int, int);
void sieve(int[], int);

int main()
{
	int x, y;
	scanf("%d %d", &x, &y);

	int a = min(x, y);
	int b = max(x, y);

	int isPrime[b+1];
	sieve(isPrime, b);

	int printed = 0;
	for(int i=a;i<=b;i++)
	{
		if(isPrime[i])
		{
			printf("%d ", i);
			printed = 1;
		}
	}

	if(printed)
	{
		printf("\n");
	}
}

int min(int x, int y)
{
	return x<y?x:y;
}

int max(int x, int y)
{
	return x>y?x:y;
}

void sieve(int isPrime[], int n)
{
	isPrime[0] = isPrime[1] = 0;
	for(int i=2;i<=n;i++)
	{
		isPrime[i] = 1;
	}

	for(int p=2;p*p<=n;p++)
	{
		if(isPrime[p])
		{
			for(int j=2*p;j<=n;j+=p)
			{
				isPrime[j] = 0;
			}
		}
	}
}
