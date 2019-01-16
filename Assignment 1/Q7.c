#include<stdio.h>

void encodeMessage(char[], int);
void decodeMessage(char[], int);

int main()
{
	int MAX_SIZE = 50;
	int length = 0;

	printf("Enter a message. Max size is 50.\n");
	
	char message[MAX_SIZE];
	while(length<MAX_SIZE)
	{
		char c;
		scanf("%c", &c);
		message[length++] = c;
		if(c == '\n')
		{
			message[length-1] = ' ';
			break;
		}
	}

	int choice;
	printf("Type 1 to encode, or 0 to decode.\n");
	scanf("%d", &choice);
	
	if(choice)
	{
		encodeMessage(message, length);
	}
	else
	{
		decodeMessage(message, length);
	}
	return 0;
}

void encodeMessage(char message[], int len)
{
	int prev = -1;
	int modify = 1;
	char newMessage[len];

	for(int i=0;i<len;i++)
	{
		char c = message[i];
		if(c != ' ')
		{
			if(modify)
			{
				c = (c<'x')?c+3:c-23;
			}
			newMessage[i] = c;
			modify = 1 - modify;
		}
		else
		{
			newMessage[i] = c;
			int start = prev + 1;
			int end = i - 1;
			for(int j=start;j<=(start+end)/2.0;j++)
			{
				int temp = newMessage[j];
				newMessage[j] = newMessage[end - j + start];
				newMessage[end - j + start] = temp;
			}
			prev = i;
		}
	}

	for(int i=0;i<len;i++)
	{
		printf("%c", newMessage[i]);
	}
	printf("\n");
}

void decodeMessage(char message[], int len)
{
	int prev = -1;
	int modify = 1;

	for(int i=0;i<len;i++)
	{
		char c = message[i];
		if(c == ' ')
		{
			int start = prev + 1;
			int end = i - 1;
			for(int j=start;j<=(start+end)/2.0;j++)
			{
				int temp = message[j];
				message[j] = message[start + end - j];
				message[start + end - j] = temp;
			}
			prev = i;
		}
	}
	
	for(int i=0;i<len;i++)
	{
		char c = message[i];
		if(c != ' ')
		{
			if(modify)
			{
				c = (c>'c')?c-3:c+23;
			}
			modify = 1 - modify;
		}
		printf("%c", c);
	}
	printf("\n");
}