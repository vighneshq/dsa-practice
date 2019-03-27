#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct
{
    int front, end, capacity, size;
    int* arr;
} Queue;
  
void createQueue(Queue* q, int n)
{
    q->capacity = n;
    q->front = 0;
    q->size = 0;
    q->end = 1;
    q->arr = malloc(n*sizeof(int));
}

int isEmpty(Queue q)
{
    return q.size == 0;
}

int isFull(Queue q)
{
    return q.size == q.capacity - 1;
}

void enqueue(Queue* q, int elem)
{
    if(!isFull(*q))
    {
        q->front = (q->front+1)%q->capacity;
        q->arr[q->front] = elem;
        q->size++;
    }
}

int dequeue(Queue *q)
{
    if(!isEmpty(*q))
    {
        int elem = q->arr[q->end];
        q->end = (q->end+1)%q->capacity;
        q->size--;
        return elem;
    }
}

void bfs(int *adj[], int n, int source, int dist[])
{
    Queue* q = malloc(n*sizeof(Queue));
    int* vis = calloc(n,sizeof(int));
    createQueue(q,n);
    enqueue(q,source);
    vis[source] = 1;
    dist[source] = 0;
    while(!isEmpty(*q))
    {
        int curr = dequeue(q);
        for(int i=0;i<n;i++)
        {
            if(!vis[i] && (adj[curr][i] == 1))
            {
                enqueue(q,i);
                vis[i] = 1;
                dist[i] = dist[curr]+1;
            }
        }
    }
    free(vis);
    free(q);
}

void createGraph(int* adj[], int n)
{
    for(int i=0;i<n;i++)
    {
        adj[i] = calloc(n,sizeof(int));
    } 
}

int min(int a, int b)
{
    return a<b?a:b;
}

int main()
{
    int n, m, s, t;
    scanf("%d %d %d %d", &n, &m, &s, &t);
    s--;
    t--;

    int* adj[n];
    createGraph(adj,n);
    for(int i=0;i<m;i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        adj[x-1][y-1] = 1;
        adj[y-1][x-1] = 1;
    }

    int ds[n], dt[n];
    bfs(adj, n, s, ds);
    bfs(adj, n, t, dt);

    int D = ds[t];
    int c = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(!adj[i][j])
            {
                int d = min(ds[i]+dt[j]+1,dt[i]+ds[j]+1);
                if(d>=D)
                {
                    c++;
                }
            }
        }
    }
    printf("%d\n", c);
}
