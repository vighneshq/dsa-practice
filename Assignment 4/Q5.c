#include<stdio.h>

int itemsMade(int arr[], int n, int k)
{
	int ans = 0;
	for(int i=0;i<n;i++)
	{
		ans += k/arr[i];
	}
	return ans;
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	int arr[n];
	int min = -1;
	for(int i=0;i<n;i++)
	{
		scanf("%d", &arr[i]);
		if(min == -1)
		{
			min = arr[i];
		}
		else
		{
			min = (min<arr[i])?min:arr[i];
		}
	}

	
	int l = 1;
	int h = m*min;
	int ans = h;
	while(l <= h)
	{
		int k = (l+h)/2;
		int items = itemsMade(arr, n, k);
		if(items >= m)
		{
			ans = (ans<k)?ans:k;
			h = k - 1;
		}
		else
		{
			l = k + 1;
		}
	}
	printf("%d\n", ans);
	return 0;
}