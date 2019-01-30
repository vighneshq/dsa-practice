#include<stdio.h>
#include<stdlib.h>

int main()
{
	const int MAX = 100;
	char string[MAX];
	scanf("%s", string);
	
	int	*letters = calloc(26, sizeof(int));
	int index = 0;
	while(string[index] != '\0')
	{
		char c = string[index++];
		letters[c-97]++;
	}

	int odd = 0;
	for(int i=0;i<26;i++)
	{
		if(letters[i]%2)	
		{
			odd++;
		}
	}

	if(odd<=1)
	{
		printf("Yes.\n");
	}
	else
	{
		printf("No.\n");
	}
	return 0;
}