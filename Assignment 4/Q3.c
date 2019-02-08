#include<stdio.h>

int main()
{
	int n;
	scanf("%d", &n);

	int arr[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d", &arr[i]);
	}

	int l = 0, r = n - 1;
	while(l <= r)
	{
		int m = (l+r)/2;
		if(l == r)
		{
			printf("%d\n", arr[m]);
			break;
		}
		else if(m%2 == 0)
		{
			if(arr[m] == arr[m+1])
			{
				l = m + 2;
			}
			else
			{
				r = m;
			}
		}
		else
		{
			if(arr[m] == arr[m-1])
			{
				l = m + 1;
			}
			else
			{
				r = m - 1;
			}
		}
	}
	return 0;
}