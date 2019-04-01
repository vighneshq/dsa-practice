#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    int tos, size;
    char *stk;
} Stack;

void createStack(Stack* s, int n)
{
    s->size = n;
    s->tos = -1;
    s->stk = malloc(n*sizeof(char));
}

int isEmpty(Stack s)
{
    return (s.tos == -1);
}

int isFull(Stack s)
{
    return (s.tos == s.size - 1);
}

void push(Stack* s, char elem)
{
    s->tos += 1;
    s->stk[s->tos] = elem;
}

char pop(Stack *s)
{
   char elem = s->stk[s->tos];
   s->tos -= 1;
   return elem;
}

int main()
{
    const int MAX_SIZE = 1E5;
    char str[MAX_SIZE];
    int len = 0;
    while(1)
    {
        char c;
        scanf("%c", &c);
        if(c == '\n')
        {
            break;
        }
        str[len++] = c;
    }
    
    Stack s;
    createStack(&s, len);

    for(int i=0;i<len;i++)
    {
        char c = str[i];
        if(c == '(' || c == '[' || c == '{')
        {
            push(&s, c);
        }
        else 
        {
            if(isEmpty(s))
            {
                printf("False\n");
                return 0;
            }
            char prev = pop(&s);
            if(c == ')' && prev != '(')
            {
                printf("False\n");
                return 0;
            }
            else if(c == ']' && prev != '[')
            {
                printf("False\n");
                return 0;
            }
            else if(c == '}' && prev != '{')
            {
                printf("False\n");
                return 0;
            }
        }
    }
    if(isEmpty(s))
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }
    return 0;
}