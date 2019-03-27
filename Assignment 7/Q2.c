#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct stack
{
    int tos, size;
    int* stk;
} Stack;

void createStack(Stack* s, int n)
{
    s->size = n;
    s->tos = -1;
    s->stk = malloc(n*sizeof(int));
}

int isEmpty(Stack* s)
{
    return (s->tos == -1);
}

void push(Stack* s, int elem)
{
    (s->tos)++;
    s->stk[s->tos] = elem;
}

int pop(Stack *s)
{
    return s->stk[(s->tos)--];
}

void createGraph(int* adj[], int n)
{
    for(int i=0;i<n;i++)
    {
        adj[i] = calloc(n,sizeof(int));
    } 
}

void fillStack(int *adj[], int n, int vis[], int curr, Stack* s)
{
    vis[curr] = 1;
    for(int i=0;i<n;i++)
    {
        if(adj[curr][i] && !vis[i])
        {
            fillStack(adj, n, vis, i, s);
        }
    }
    push(s, curr);
}

void dfs(int *adj_comp[], int n, int vis[], int curr, int comp[], int count)
{
    vis[curr] = 1;
    comp[curr] = count;
    for(int i=0;i<n;i++)
    {
        if(adj_comp[curr][i] && !vis[i])
        {
            dfs(adj_comp, n, vis, i, comp, count);
        }
    }
}

int min(int a, int b)
{
    return a<b?a:b;
}

int main()
{
    int n;
    scanf("%d", &n);

    int cost[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d", &cost[i]);
    }

    int m;
    scanf("%d", &m);

    int *adj[n], *adj_comp[n];
    createGraph(adj, n);
    createGraph(adj_comp, n);
    for(int i=0;i<m;i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u-1][v-1] = 1;
        adj_comp[v-1][u-1] = 1;
    }

    int *vis = calloc(n, sizeof(int));

    Stack s;
    createStack(&s, n);
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            fillStack(adj, n, vis, i, &s);
        }
    }

    for(int i=0;i<n;i++)
    {
        vis[i] = 0;
    }
    
    int count = 0;
    int comp[n];
    while(!isEmpty(&s))
    {
        int curr = pop(&s);
        if(!vis[curr])
        {   
            dfs(adj_comp, n, vis, curr, comp, count);
            count++;
        }
    }

    int c[count], num[count];
    for(int i=0;i<count;i++)
    {
        c[i] = INT_MAX;
        num[i] = 0;
    }
    for(int i=0;i<n;i++)
    {
        c[comp[i]] = min(c[comp[i]], cost[i]);
    }    
    for(int i=0;i<n;i++)
    {
        if(cost[i] == c[comp[i]])
        {
            num[comp[i]]++;
        }
    }
    int total_cost = 0, total_ways = 1;
    for(int i=0;i<count;i++)
    {
        total_cost += c[i];
        total_ways *= num[i];
    }
    printf("%d %d\n", total_cost, total_ways);
    return 0;
}