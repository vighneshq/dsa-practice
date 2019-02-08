#include<stdio.h>

// Assumes sorted input
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

	int pos = -1;
	int l = 1;
	int r = n;
	while(l <= r)
	{
		pos = (l + r)/2;
		if(arr[pos] == k)
		{
			printf("Naruto %d\n", pos);
			return 0;
		}
		else if(arr[pos] < k)
		{
			l = pos + 1;
		}
		else 
		{
			r = pos - 1;
		}
	}
	if(arr[pos] < k)
	{
		printf("Sasuke %d\n", pos+1);
	}
	else
	{
		printf("Sasuke %d\n", pos);
	}
	return 0;
}