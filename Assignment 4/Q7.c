#include<stdio.h>

int main()
{
	int n;
	scanf("%d", &n);

	int arr[n+1];
	for(int i=1;i<=n;i++)
	{
		scanf("%d", &arr[i]);
	}

	int k;
	scanf("%d", &k);

	int l = 1;
	int r = n;
	while(l <= r)
	{
		int m = (l + r)/2;
		if(arr[m] == k)
		{
			printf("%d\n", m);
			return 0;
		}
		else if(arr[m] < k)
		{
			if(m == 1 || arr[m-1] != k)
			{
				l = m + 1;
			}
			else
			{
				printf("%d\n", m-1);
				return 0;
			}
		}
		else 
		{
			if(m == n || arr[m+1] != k)
			{
				r = m - 1;
			}
			else
			{
				printf("%d\n", m+1);
				return 0;
			}
		}
	}
	printf("%d\n", -1);
	return 0;
}