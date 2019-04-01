#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    int size, capacity;
    int* arr;
} Heap;

void swap(Heap* h, int i, int j)
{
    int t = h->arr[i];
    h->arr[i] = h->arr[j];
    h->arr[j] = t;
}

void createHeap(Heap* h, int n)
{
    h->size = n;
    h->capacity = n;
    h->arr = malloc((n+1)*sizeof(int));
}

int left(int i)
{
    return 2*i;
}

int right(int i)
{
    return 2*i+1;
}

int parent(int i)
{
    return i/2;
}

void minHeapify(Heap* h, int i)
{
    int l = left(i);
    int r = right(i);
    int index = i;
    if(l <= h->size && h->arr[l] < h->arr[index])
    {
        index = l;
    }
    if(r <= h->size && h->arr[r] < h->arr[index])
    {
        index = r;
    }
    swap(h, i, index);
    if(index != i)
    {
        minHeapify(h, index);
    }
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    Heap* h;
    createHeap(h, n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d", &(h->arr[i]));
    }
    for(int i=n/2+1;i>=1;i--)
    {
        minHeapify(h, i);
    }
    int count = 0;
    while(h->size > 1 && h->arr[1] < k)
    {   
        int min = h->arr[1];
        swap(h, 1, h->size);
        h->size -= 1;
        minHeapify(h, 1);
        h->arr[1] = 2*(h->arr[1]) + min;
        minHeapify(h, 1);
        count++;
    }
    if(h->arr[1] < k)
    {
        printf("Not possible\n");
    }
    else
    {
        printf("%d\n", count);
    }
    return 0;
}