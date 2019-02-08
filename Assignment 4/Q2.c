#include<stdio.h>

int solved(int v, int k)
{
	int count = 0;
	while(v > 0)
	{
		count+= v;
		v/=k;
	}
	return count;
}

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);

	int l = n*(k-1)/k;
	int h = n;
	int ans = n;
	while(l <= h)
	{
		int m = (l + h)/2;
		int done = solved(m, k);
		if(done == n)
		{
			ans = m;
			break;
		}
		else if(done < n)
		{
			l = m + 1;
		}
		else
		{
			ans = (ans < m)?ans:m;
			h = m - 1;
		}
	}
	printf("%d\n", ans);
	return 0;
}