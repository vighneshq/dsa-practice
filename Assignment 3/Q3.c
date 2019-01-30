#include<stdio.h>
#include<stdlib.h>

// Enum for custom bool
typedef enum {false, true} bool;

// Struct for Linked List node
typedef struct node
{
	int data;
	struct node* next;
} Node;

// Function for Linked List
void traverse(Node*);
void insertAtBeg(Node**, int);
void update(Node**, int, int);

int main()
{
	int k;
	scanf("%d", &k);
	
	int input;
	int len = 0;

	Node* head = NULL;
	while(1)
	{
		scanf("%d", &input);
		if(input == -1)
		{
			break;
		}
		insertAtBeg(&head, input);
		len++;
	}
	update(&head, k, len);
	traverse(head);
}

void traverse(Node* head)
{
	if(head == NULL)
	{
		return;
	}
	while(head != NULL)
	{
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}

void insertAtBeg(Node** head, int elem)
{
	Node* new = malloc(sizeof(Node));
	new->next = *head;
	new->data = elem;

	*head = new;
}

void update(Node** head, int k, int len)
{
	if(k > len)
	{
		return;
	}
	Node* newHead = NULL;
	int pos = 0;

	Node* temp = *head;
	Node* prev = NULL;
	while(temp != NULL)
	{
		if((len-pos)%k == 0)
		{
			Node* delete = temp;
			if(prev == NULL)
			{
				*head = temp->next;
			}
			else
			{
				prev->next = temp->next;
			}
			temp = temp->next;
			insertAtBeg(&newHead, delete->data);
			free(delete);
		}
		else
		{
			prev = temp;
			temp = temp->next;
		}
		pos++;
	}
	
	temp = newHead;
	if(temp != NULL)
	{
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = *head;
	}
	*head = newHead;
}