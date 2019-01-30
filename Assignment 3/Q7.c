#include<stdio.h>

void caesar(char*, int);

int main()
{
	const int MAX = 100;
	char string[MAX];
	scanf("%s", string);

	caesar(string, 3);	
	printf("%s\n", string);
}

void caesar(char* string, int k)
{
	int index = 0;
	while(string[index] != '\0')
	{
		char c = string[index];
		c = (c + k - 97)%26 + 97;	
		string[index++] = c;
	}
}