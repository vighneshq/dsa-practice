#include<stdio.h>
#include<limits.h>

void merge(int arr[], int p, int q, int r)
{
	int n = q - p + 1;
	int m = r - q;
	int L[n], R[m];

	for(int i=0;i<n;i++)
	{
		L[i] = arr[p+i];
	}
	for(int j=0;j<m;j++)
	{
		R[j] = arr[q+1+j];
	}

	int i = 0, j = 0, k = p;
	while(i < n && j < m)
	{
		if(L[i] < R[j])
		{
			arr[k++] = L[i++];
		}
		else
		{
			arr[k++] = R[j++];
		}
	}

	if(i == n)
	{
		while(j < m)
		{
			arr[k++] = R[j++];
		}
	}
	else
	{
		while(i < n)
		{
			arr[k++] = L[i++];
		}	
	}
}

void mergesort(int arr[], int l, int r)
{
	if(l < r)
	{
		int m = (l+r)/2;
		mergesort(arr, l, m);
		mergesort(arr, m+1, r);
		merge(arr, l, m, r);
	}
}

int abs(int x)
{
	if(x < 0)
	{
		return -x;
	}
	return x;
}

int findCost(int h[], int c[], int n, int towers, int eq_h)
{
	int temp[n];
	for(int i=0;i<n;i++)
	{
		temp[i] = c[i]*(abs(h[i] - eq_h) - h[i]);
	}
	mergesort(temp, 0, n-1);
	int sum = 0;
	for(int i=0;i<towers;i++)
	{	
		sum += temp[i];
	}
	for(int i=0;i<n;i++)
	{
		sum += c[i]*h[i];
	}
	return sum;
}

int main()
{
	int n;
	scanf("%d", &n);

	int h[n], c[n];
	int m = 0;
	for(int i=0;i<n;i++)
	{
		scanf("%d", &h[i]);
		m+= h[i];
	}
	for(int i=0;i<n;i++)
	{
		scanf("%d", &c[i]);
	}

	int cmin = INT_MAX, height = -1, towers = -1;
	for(int eq_h=1;eq_h*eq_h<=m;eq_h++)
	{
		if(m%eq_h == 0)
		{
			int num = m/eq_h;
			if(num <= n)
			{
				int cost = findCost(h, c, n, num, eq_h);
				if(cost <= cmin)
				{
					cmin = cost;
					height = eq_h;
					towers = num;
				}
			}
			if(eq_h <= n && eq_h != num)
			{
				int cost = findCost(h, c, n, eq_h, num);
				if(cost <= cmin)
				{
					cmin = cost;
					height = num;
					towers = eq_h;
				}
			}
		}	
	}

	printf("%d %d %d\n", cmin, towers, height);
	return 0;
}