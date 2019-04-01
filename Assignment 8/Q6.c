#include<stdio.h>
#include<stdlib.h>

typedef struct 
{
    int elem, min;
} Pair;

typedef struct
{
    int tos, size;
    Pair *stk;
} Stack;

int min(int a, int b)
{
    return a<b?a:b;
}

void createStack(Stack* s, int n)
{
    s->size = n;
    s->tos = -1;
    s->stk = malloc(n*sizeof(Pair));
}

int isEmpty(Stack s)
{
    return (s.tos == -1);
}

int isFull(Stack s)
{
    return (s.tos == s.size - 1);
}

Pair top(Stack s)
{
    return s.stk[s.tos];
}

void push(Stack* s, int elem)
{
    Pair p = {elem, elem};
    if(!isEmpty(*s))
    {
        Pair top_pair = top(*s);
        p.min = min(elem, top_pair.min);
    }
    s->tos += 1;
    s->stk[s->tos] = p;
}

Pair pop(Stack *s)
{
   Pair elem = s->stk[s->tos];
   s->tos -= 1;
   return elem;
}

int main()
{
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Minimum\n");
    printf("4. Exit\n");

    int choice;
    Stack s;
    createStack(&s, 1E5);
    while(1)
    {
        scanf("%d", &choice);
        if(choice == 1)
        {
            int elem;
            scanf("%d", &elem);
            push(&s, elem);
        }
        else if(choice == 2)
        {
            Pair p = pop(&s);
            printf("%d\n", p.elem);
        }
        else if(choice == 3)
        {
            Pair p = top(s);
            printf("%d\n", p.min);
        }
        else
        {
            break;
        }
    }
    return 0;
}
