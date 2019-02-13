#include<stdio.h>

void merge(int arr[], int p, int q, int r, int* count)
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

	int i = 0, j = 0;
	int k = p;
	while(i < n && j < m)
	{
		if(L[i] <= R[j])
		{
			arr[k++] = L[i++];
		}
		else
		{
			(*count) += n - i;
			arr[k++] = R[j++];
		}
	}

	while(i < n)
	{
		arr[k++] = L[i++];
	}
	
	while(j < m)
	{
		arr[k++] = R[j++];
	}
	
}

void mergesort(int arr[], int l, int r, int* count)
{
	if(l < r)
	{
		int m = (l+r)/2;
		mergesort(arr, l, m, count);
		mergesort(arr, m+1, r, count);
		merge(arr, l, m, r, count);
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

	int inversions = 0;
	mergesort(arr, 0, n - 1, &inversions);
	printf("%d\n", inversions);
	return 0;
}