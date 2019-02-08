#include<stdio.h>

int search(int arr[], int l, int r, int k)
{
	if(l <= r)
	{
		int m = (l + r)/2;
		if(arr[m] == k)
		{
			return m;
		}
		else if(arr[l] <= arr[m])
		{
			if(arr[l] <= k && k <= arr[m])
			{
				return search(arr, l, m-1, k);
			}
			return search(arr, m+1,r,k);
		}
		else
		{
			if(arr[m] <= k && k <= arr[r])
			{
				return search(arr, m+1, r, k);
			}
			return search(arr, l, m-1, k);
		}
	}
	return -2;
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

	int k;
	scanf("%d", &k);

	int pos = search(arr, 0, n - 1, k);	
	printf("%d\n", pos+1);
	return 0;
}