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
	int n;
	scanf("%d", &n);

	int arr[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d", &arr[i]);
	}
	mergesort(arr, 0, n-1);

	int d;
	scanf("%d", &d);
	
	int l = 0, r = 1;
	while(l < n && r < n)
	{
		if(arr[r] - arr[l] == d)
		{
			printf("%d\n", arr[r] + arr[l]);
			return 0;
		}
		else if(arr[r] - arr[l] < d)
		{
			r++;
		}
		else
		{
			l++;
		}
	}
	printf("-1\n");
	return 0;
}