#include<stdio.h>
#include<stdlib.h>

typedef struct nodeType
{
	int data;
	struct nodeType* prev;
	struct nodeType* next;
} Node;

void traverse(Node*, int);
void insertSingle(Node**, int);
void findSingle(Node*, int);
void insertDouble(Node**, Node**, int);
void findDouble(Node*, int);
void insertCircular(Node**, int);
void findCircular(Node*, int);

int main()
{
	printf("0 - Singly LL, 1 - Doubly LL, 2 - Circular LL.\n");
	int choice, k;
	scanf("%d", &choice);
	char c;
	
	// Stupid duplicated code warning.
	if(choice == 0)
	{
		printf("I - Insert. F - Find & Quit.\n");
		scanf(" %c", &c);	
		Node* head = NULL;
		while(c != 'F')
		{
			int x;
			scanf("%d", &x);
			insertSingle(&head, x);
			printf("I - Insert. F - Find & Quit.\n");
			scanf(" %c", &c);
		}
		printf("Enter k.\n");
		int k;
		scanf("%d", &k);
		findSingle(head, k);
	}
	else if(choice == 1)
	{
		printf("I - Insert. F - Find & Quit.\n");
		scanf(" %c", &c);	
		Node* head = NULL;
		Node* tail = NULL;
		while(c != 'F')
		{
			int x;
			scanf("%d", &x);
			insertDouble(&head, &tail, x);
			printf("I - Insert. F - Find & Quit.\n");
			scanf(" %c", &c);
		}
		printf("Enter k.\n");
		int k;
		scanf("%d", &k);
		findDouble(tail, k);
	}
	else if(choice == 2)
	{
		printf("I - Insert. F - Find & Quit.\n");
		scanf(" %c", &c);	
		Node* head = NULL;
		while(c != 'F')
		{
			int x;
			scanf("%d", &x);
			insertCircular(&head, x);
			printf("I - Insert. F - Find & Quit.\n");
			scanf(" %c", &c);
		}
		printf("Enter k.\n");
		int k;
		scanf("%d", &k);
		findCircular(head, k);
	}
}

void traverse(Node* head, int choice)
{
	if(head == NULL)
	{
		return;
	}
	Node* temp = head;
	if(choice != 2)
	{
		while(temp != NULL)
		{
			printf("%d ", temp->data);
			temp = temp->next;
		}
		printf("\n");
	}
	else
	{
		while(temp->next != head)
		{
			printf("%d ", temp->data);
			temp = temp->next;
		}
		printf("%d ", temp->data);
		printf("\n");
	}
}


void insertSingle(Node** headRef, int x)
{
	Node* temp = malloc(sizeof(Node*));
	temp->data = x;
	temp->next = NULL;
	if(*headRef == NULL)
	{
		*headRef = temp;
		return;
	}

	Node* last = *headRef;
	while(last->next != NULL)
	{
		last = last->next;
	}
	last->next = temp;
}

void findSingle(Node* head, int k)
{
	Node* temp = head;
	int len = 0;
	while(temp != NULL)
	{
		len++;
		temp = temp->next;
	}
	if(len < k)
	{
		printf("Value of K exceeded limit.\n");
		return;
	}
	temp = head;
	int pos = 1;
	while(pos < len - k + 1)
	{
		temp = temp->next;
		pos++;
	}
	printf("%d\n", temp->data);
}

void insertDouble(Node** headRef, Node** tailRef, int x)
{
	Node* temp = malloc(sizeof(Node*));
	temp->data = x;
	temp->next = NULL;
	temp->prev = NULL;
	if(*headRef == NULL)
	{
		*headRef = temp;
		*tailRef = temp;
		return;
	}
	(*tailRef)->next = temp;
	temp->prev = *tailRef;
	*tailRef = temp;
}

void findDouble(Node* tail, int k)
{
	if(tail == NULL)
	{
		return;
	}
	int pos = 0;
	Node* temp = tail;
	while(temp != NULL)
	{
		pos++;
		if(pos == k)
		{
			printf("%d\n", temp->data);
			return;
		}
		temp = temp->prev;
	}
	printf("Value of K exceeded limit.\n");
}

void insertCircular(Node** headRef, int x)
{
	Node* temp = malloc(sizeof(Node*));
	temp->data = x;
	if(*headRef == NULL)
	{
		*headRef = temp;
		temp->next = temp;
		return;
	}
	Node* last = *headRef;
	while(last->next != *headRef)
	{
		last = last->next;
	}
	temp->next = *headRef;
	last->next = temp;
}

void findCircular(Node* head, int k)
{
	if(head == NULL)
	{
		printf("Value of K exceeded limit.\n");
		return;
	}
	Node* temp = head;
	int len = 1;
	while(temp->next != head)
	{
		len++;
		temp = temp->next;
	}
	if(len < k)
	{
		printf("Value of K exceeded limit.\n");
		return;
	}
	temp = head;
	int pos = 1;
	while(pos < len - k + 1)
	{
		temp = temp->next;
		pos++;
	}
	printf("%d\n", temp->data);
}
