#include<stdio.h>
#include<stdlib.h>

// Enum for custom bool
typedef enum {false, true} bool;

// Struct for Doubly Linked List
typedef struct nodeType
{
	int id;
	struct nodeType* prev;
	struct nodeType* next;
	int color;
} Node;

void insert(Node**, int, int);
void findLoops(Node*);
void traverse(Node*);
void assignColors(Node*);

int main()
{
	Node* head = NULL;
	while(1)
	{
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		if(x < 0 || y < 0 || z < 0)
		{
			break;
		}
		insert(&head, x, y);
	}
	findLoops(head);
}

void insert(Node** headRef, int x, int y)
{
	Node* new = (Node*) malloc(sizeof(Node));
	new->id = x;
	new->next = NULL;
	new->prev = NULL;

	if(*headRef == NULL)
	{
		new->prev = NULL;
		*headRef = new;
		return;
	}

	Node* temp = *headRef;
	while(temp->next != NULL)
	{
		if(temp->id == y)
		{
			new->prev = temp;
		}
		temp = temp->next;
	}
	temp->next = new;
	if(temp->id == y)
	{
		new->prev = temp;
	}
	else if(temp->id == 0)
	{
		new->prev = NULL;
	}
}

void findLoops(Node* head)
{
	while(head != NULL)
	{
		if(head->prev != NULL)
		{
			Node* temp = head->prev;
			if(temp->id != head->id - 1)
			{
				while(temp != head)
				{
					printf("%d ", temp->id);
					temp = temp->next;
				}
				printf("%d %d\n", temp->id, (temp->prev)->id);
			}
		}
		head = head->next;
	}
}

void traverse(Node* head)
{
	Node* temp = head;
	while(temp != NULL)
	{
		printf("%d ", temp->id);
		temp = temp->next;
	}
	printf("\n");
}

void assignColors(Node* head)
{
	printf("Hello, World.\n");
}