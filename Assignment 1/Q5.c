#include<stdio.h>
#include<stdlib.h>

typedef struct node 
{
	int data;
	struct node* next;
} Node;

void traverse(Node*);
void insert(Node**, int);
void search(Node*, int);
void delete(Node**, int);
void swap(Node**, int);

int main()
{
	printf("Enter the number of elements in the list.\n");
	int n;
	scanf("%d", &n);

	Node* head = NULL;
	for(int i=0;i<n;i++)
	{
		int x;
		scanf("%d", &x);
		insert(&head, x);
	}

	int choice;
	int x;
	do
	{
		printf("0. Exit.\n");
		printf("1. Print.\n");
		printf("2. Search.\n");
		printf("3. Delete.\n");
		printf("4. Swap.\n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 0:
				continue;
			case 1:
				traverse(head);
				break;
			case 2:
				printf("Enter element to search for.\n");
				scanf("%d", &x);
				search(head, x);
				break;
			case 3:
				printf("Enter element to delete.\n");
				scanf("%d", &x);
				delete(&head, x);
				break;
			case 4:
				printf("Enter element to swap.\n");
				scanf("%d", &x);
				swap(&head, x);
				break;
			default:
				printf("Enter valid choice.\n");
		}
	} while(choice != 0);
}

void traverse(Node* head)
{
	Node* temp = head;
	int printed = 0;
	while(temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
		printed = 1;
	}

	if(printed)
	{
		printf("\n");
	}
}

void insert(Node** headRef, int elem)
{
	Node* temp = (Node *)malloc(sizeof(Node));
	temp->data = elem;
	temp->next = NULL;
	if(*headRef == NULL)
	{
		*headRef = temp;
	}
	else
	{
		Node* last = *headRef;
		while(last->next != NULL)
		{
			last = last->next;
		}
		last->next = temp;
	}
}

void search(Node* head, int elem)
{
	int count = 1;
	Node* temp = head;
	while(temp != NULL)
	{
		if(temp->data == elem)
		{
			printf("Found at position : %d\n", count);
		}
		temp = temp->next;
		count++;
	}
}

void delete(Node** headRef, int elem)
{
	Node* temp = *headRef;
	Node* prev = NULL;

	int first = 1;
	while(temp != NULL)
	{
		if(temp->data != elem)
		{
			prev = temp;
			temp = temp->next;
		}
		else
		{
			if(first)
			{
				first = 0;
				prev  = temp;
				temp = temp->next;
			}
			else
			{
				prev->next = temp->next;
				Node* deleted = temp;
				temp = temp->next;
				free(deleted);
			}
		}
	}
}

void swap(Node** headRef, int elem)
{
	Node* temp = *headRef;
	Node* prev = NULL;

	while(temp != NULL)
	{
		if(temp->data == elem)
		{
			break;
		}
		prev = temp;
		temp = temp->next;
	}
	if(temp->next != NULL)
	{
		Node* succ = temp->next;
		if(prev == NULL)
		{
			temp->next = succ->next;
			succ->next = temp;
			*headRef = succ;
		}
		else
		{
			prev->next = succ;
			temp->next = succ->next;
			succ->next = temp;
		}
	}
}
