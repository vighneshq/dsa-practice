#include<stdio.h>
#include<stdlib.h>

int main()
{
	const int MAX = 1000;
	char string[MAX];
	scanf("%s", string);
	
	int M;
	scanf("%d", &M);
	while(M--)
	{
		int f, r, k;
		scanf("%d %d %d", &f, &r, &k);
		f--;
		r--;
		k = k%(r-f+1);
		char temp[k];
		for(int i=k-1;i>=0;i--)
		{
			temp[k-1-i] = string[r-i];
		}
		for(int i=r-k;i>=f;i--)
		{
			string[i+k] = string[i];
		}
		for(int i=0;i<k;i++)
		{
			string[f+i] = temp[i];
		}
	}

	printf("%s\n", string);
	return 0;
}