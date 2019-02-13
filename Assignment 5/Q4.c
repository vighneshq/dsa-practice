#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int elem, pos;
} Pair;

void swap(Pair *a, Pair *b)
{
	Pair t = *a;
	*a = *b;
	*b = t;
}

// Too lazy to write another sort
int bubblesort(Pair p[], int n)
{
	for(int i=0;i<n;i++)
	{
		int swapped = 0;
		for(int j=0;j<n-1-i;j++)
		{
			if(p[j].elem > p[j+1].elem)
			{
				swap(&p[j], &p[j+1]);
				swapped = 1;
			}
		}
		if(!swapped)
		{
			break;
		}
	}
}

int main()
{
	int n;
	scanf("%d", &n);

	Pair p[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d", &p[i].elem);
		p[i].pos = i;
	}
	
	bubblesort(p,n);
	
	int* vis = calloc(n, sizeof(int));
	int count = 0;
	for(int i=0;i<n;i++)
	{
		if(vis[i])
		{
			continue;
		}

		vis[i] = 1;
		int j = p[i].pos;
		while(j != i)
		{
			vis[j] = 1;
			j = p[j].pos;
		}
		count++;
	}
	printf("%d\n", n - count);
	return 0;
}