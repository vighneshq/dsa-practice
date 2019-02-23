#include<stdio.h>

typedef struct
{
    int x, y;
} Edge;

void swap(int arr[], int pos[], int x, int y)
{
    int t1 = arr[x];
    int t2 = pos[x];
    arr[x] = arr[y];
    pos[x] = pos[y];
    arr[y] = t1;
    pos[y] = t2;
}

int bubblesort(int arr[], int pos[], int n)
{
    for(int i=0;i<n;i++)
    {
        int swapped = 0;
        for(int j=0;j<n-1-i;j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(arr, pos, j, j + 1);
                swapped = 1;
            }
        }
        if(!swapped)
        {
            break;
        }
    }
}

void addEdge(Edge edges[], int pos[], int a, int b, int e)
{
    edges[e].x = pos[a]+1;
    edges[e].y = pos[b]+1;
}

int main()
{
    int n;
    scanf("%d", &n);

    int d[n], pos[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d", &d[i]);
        pos[i] = i;
    }
    
    if(n <= 2)
    {
        printf("-1\n");
        return 0;
    }
    else
    {
        bubblesort(d, pos, n);
        if(d[0] != 0)
        {
            printf("-1\n");
            return 0; 
        }
    }

    Edge edges[n];
    int curr = 1, prev = 0;
    int e = 0;
    int x = -1, y = -1;
    while(curr < n)
    {
       
        if(d[curr] != d[curr - 1])
        {
            prev = curr - 1;
        }
        else
        {
            x = curr;
            y = curr-1;
        }
        if(d[curr] != d[prev] + 1)
        {
            printf("-1\n");
            return 0;
        }
        else
        {
            addEdge(edges, pos, prev, curr, e);
            e++;
        }
        curr++;
    }
    if(x != -1 && y != -1)
    {
        addEdge(edges, pos, x, y, e);
        e++;
    }
    else
    {
        printf("-1\n");
        return 0;
    }
    printf("%d\n", e);
    for(int i=0;i<e;i++)
    {
        printf("%d %d\n", edges[i].x, edges[i].y);
    }
    return 0;
}