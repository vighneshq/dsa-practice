#include<stdio.h>
#include<stdlib.h>

int main()
{
	const int MAX = 1000;
	char T[MAX], P[MAX];
	scanf("%s\n", T);
	scanf("%s", P);
	
	int N;
	scanf("%d", &N);
	
	int a[N];
	for(int i=0;i<N;i++)
	{
		scanf("%d", &a[i]);
	}

	// int *tlet = calloc(26, sizeof(int));
	// int *plet = calloc(26, sizeof(int));

	// for(int i=0;i<N;i++)4
	// {
	// 	char c = T[i];
	// 	tlet[c-97]++;
	// }
	// int index = 0;
	// while(P[index] != '\0')
	// {
	// 	char c = P[index++];
	// 	plet[c-97]++;
	// }
	
	// int i;
	// for(i=0;i<N;i++)
	// {
	// 	index = a[i];
	// 	char c = T[index-1];
	// 	tlet[c-97]--;
	// 	if(tlet[c-97] < plet[c-97])
	// 	{
	// 		break;
	// 	}
	// }
	// printf("%d\n", i);
	return 0;
}