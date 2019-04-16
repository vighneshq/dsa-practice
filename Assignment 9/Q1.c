#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    int t, e, r, i;
}Process;

typedef struct
{
    int size, cap, front, rear;
    Process *queue;
}Queue;

void createQueue(Queue *q, int n)
{
    q->cap = n;
    q->size = 0, q->rear = 0;
    q->front = 1;
    q->queue = malloc(n*sizeof(Process));
}

void enqueue(Queue *q, Process elem)
{
    q->size += 1;
    q->rear = (q->rear + 1)%q->cap;
    q->queue[q->rear] = elem;
}

Process dequeue(Queue *q)
{
    q->size -= 1;
    Process elem = q->queue[q->front];
    q->front = (q->front + 1)%q->cap;
    return elem;
}

int isEmpty(Queue *q)
{
    return (q->size == 0);
}

void swap(Process *a, Process *b)
{
    Process t = *a;
    *a = *b;
    *b = t;
}

void bubblesort(Process p[], int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(p[i].t > p[i+1].t)
            {
                swap(&p[i], &p[i+1]);
            }
        }
    }
}

int min(int a, int b)
{
    return (a<b)?a:b;
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    Process p[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d %d", &p[i].t, &p[i].e);
        p[i].r = p[i].e;
        p[i].i = i;
    }
    bubblesort(p, n);
    
    Queue *q = malloc(sizeof(Queue));
    createQueue(q, n);
    
    int wt = 0, ct = 0, enqueued = 0;
    while(1)
    {
        if(isEmpty(q))
        {
            if(enqueued == n)
            {
                break;
            }
            ct = p[enqueued].t;
        }
        while(enqueued < n && p[enqueued].t <= ct)
        {
            enqueue(q, p[enqueued]);
            enqueued++;
        }
        Process curr = dequeue(q);
        ct += min(k, curr.r);
        printf("%d %d\n", curr.i, ct);
        curr.r -= min(k, curr.r);
        while(enqueued < n && p[enqueued].t <= ct)
        {
            enqueue(q, p[enqueued]);
            enqueued++;
        }
        if(curr.r == 0)
        {
            wt += ct - curr.t - curr.e;
        }
        else
        {
            enqueue(q, curr);
        }
    }
    printf("\n%f\n", wt/(double)n);
    return 0;
}