#include<stdio.h>
#include<string.h>

typedef struct
{
    int v, d, w_d;
} Node;

void swap(Node* a, Node* b)
{
    Node t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(Node minHeap[], int size, int i)
{
    int l = 2*i;
    int r = 2*i+1;
    int index = i;
    if(l<=size && minHeap[l].w_d < minHeap[index].w_d)
    {
        index = l;
    }
    if(r<=size && minHeap[r].w_d < minHeap[index].w_d)
    {
        index = r;
    }
    if(index != i)
    {
        swap(&minHeap[i], &minHeap[index]);
        minHeapify(minHeap, size, index);
    }
}

void insertMinHeap(Node minHeap[], int* size, Node elem)
{
    *size += 1;
    int i = *size;
    minHeap[i] = elem;
    while(i > 1 && minHeap[i].w_d < minHeap[i/2].w_d)
    {
        swap(&minHeap[i], &minHeap[i/2]);
        i /= 2;
    }
}

Node removeMinHeap(Node minHeap[], int* size)
{
    Node top = minHeap[1];
    swap(&minHeap[1], &minHeap[*size]);
    *size -= 1;
    minHeapify(minHeap, *size, 1);
    return top;
}

int min(int a, int b)
{
    return a<b?a:b;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int w[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            w[i][j] = -1;
        }
    }

    for(int i=0;i<m;i++)
    {
        int u, v, wgt;
        scanf("%d %d %d", &u, &v, &wgt);
        w[u][v] = wgt;
    }

    int t;
    scanf("%d", &t);
    while(t--)
    {
        int src, dest, k;
        scanf("%d %d %d", &src, &dest, &k);

        Node minHeap[10005];
        int d[n], w_d[n], vis[n], index = 0;
        memset(vis, 0, n*sizeof(int));
        Node source = {src, 0, 0};
        vis[src] = 1;
        w_d[src] = 0;
        d[src] = 0;
        insertMinHeap(minHeap, &index, source);
        int done = 0;
        while(index != 0)
        {
            // Just printing for veritifcation
            for(int i=1;i<=index;i++)
            {   
                printf("%d %d %d |", minHeap[i].v, minHeap[i].d, minHeap[i].w_d);
            }
            printf("\n");
            Node curr = removeMinHeap(minHeap, &index);
            if(curr.v == dest)
            {
                printf("%d\n", curr.w_d);
                done = 1;
                break;
            }
            else if(curr.d > k)
            {
                continue;
            }
            else
            {
                for(int i=0;i<n;i++)
                {
                    if(w[curr.v][i] != -1)
                    {
                        Node new = {i, curr.d+1, curr.w_d + w[curr.v][i]};
                        if(!vis[i])
                        {
                            vis[i] = 1;
                            w_d[i] = new.w_d;
                            d[i] = new.d;
                            insertMinHeap(minHeap, &index, new);
                        }
                        else if(new.d < d[i])
                        {
                            d[i] = new.d;
                            w_d[i] = min(w_d[i], new.w_d);
                            insertMinHeap(minHeap, &index, new);
                        }
                        else if(new.w_d < w_d[i])
                        {
                            w_d[i] = new.w_d;
                            d[i] = min(d[i], new.d);
                            insertMinHeap(minHeap, &index, new);
                        }
                    }
                }
            }
        }
        if(!done)
        {
            printf("Not possible\n");
        }
    }
    return 0;
}