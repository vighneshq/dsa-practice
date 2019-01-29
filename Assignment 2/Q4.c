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
void assignColors(Node*, int);

int main()
{
	Node* head = NULL;
	int n = 0;
	while(1)
	{
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		if(x < 0 || y < 0 || z < 0)
		{
			break;
		}
		insert(&head, x, y);
		n++;
	}
	findLoops(head);
	assignColors(head, n);
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

void assignColors(Node* head, int n)
{
	if(head == NULL)
	{
		return;
	}
	int colors[n];
	int val = 0, index = 0;
	colors[index++] = val;
	val++;

	Node* curr = head->next;
	Node* temp = head;
	while(curr != NULL)
	{
		Node* prev = curr->prev;
		if( prev == NULL || prev == temp)
		{
			if(index == 1)
			{
				colors[index++] = val;
			}
			else
			{
				colors[index] = colors[index-2];
				index++;
			}
		}
		else
		{
			val = (val+1)%3;
			if(colors[prev->id] == val)
			{
				val = (val+1)%3;
			}
			colors[index++] = val;
		}
		temp = curr;
		curr = curr->next;
	}

	for(int i=0;i<n;i++)
	{
		printf("%d ", colors[i]);
	}
	printf("\n");
}