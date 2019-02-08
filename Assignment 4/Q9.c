#include<stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	int ans = 0;
	while(n--)
	{
		int temp;
		scanf("%d", &temp);
		ans = ans^temp;
	}
	printf("%d\n", ans);
	return 0;
}