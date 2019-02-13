#include<stdio.h>

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

int main()
{
	int n, S;
	scanf("%d %d", &n, &S);

	int arr[n+1];
	for(int i=1;i<=n;i++)
	{
		scanf("%d", &arr[i]);
	}

	int l = 0, h = n;
	int max = 0, cost = 0;
	while(l <= h)
	{
		int k = (l+h)/2;
		int temp[n+1];
		for(int i=1;i<=n;i++)
		{
			temp[i] = arr[i] + i*k;
		}
		mergesort(temp, 1, n);

		int sum = 0;
		for(int i=1;i<=k;i++)
		{
			sum+= temp[i];
		}
		if(sum == S)
		{
			max = k;
			cost = sum;
			break;
		}
		else if(sum <= S)
		{
			max = k;
			cost = sum;
			l = k + 1;
		}
		else
		{
			h = k - 1;
		}
	}
	printf("%d %d\n", max, cost);
	return 0;
}