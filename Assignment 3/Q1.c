#include<stdio.h>
#include<stdlib.h>

typedef enum {false, true} bool;

bool check(char[], char[], int);

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

	bool ok = true;
	int i;
	for(i=0;i<N;i++)
	{
		int index = a[i] - 1;
		T[index] = '-';
		ok = check(T, P, N);
		if(!ok)
		{
			break;
		}
	}
	printf("%d\n", i);	
	return 0;
}

bool check(char T[], char P[], int N)
{
	int j = 0;
	for(int i=0;i<N;i++)
	{
		if(T[i] == P[j])
		{
			j++;
		}
	}
	return P[j] == '\0';
}