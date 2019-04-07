#include<stdio.h>

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void maxHeapify(int maxHeap[], int size, int i)
{
    int l = 2*i;
    int r = 2*i+1;
    int index = i;
    if(l <= size && maxHeap[l] > maxHeap[index])
    {
        index = l;
    }
    if(r <= size && maxHeap[r] > maxHeap[index])
    {
        index = r;
    }
    if(index != i)
    {
        swap(&maxHeap[i], &maxHeap[index]);
        maxHeapify(maxHeap, size, index);
    }
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    int maxHeap[n+1];
    for(int i=1;i<=n;i++)
    {
        scanf("%d", &maxHeap[i]);
    }

    for(int i=n/2;i>=1;i--)
    {
        maxHeapify(maxHeap, n, i);
    }

    int meat = 0;
    while(k--)
    {
        meat += maxHeap[1];
        maxHeap[1] /= 2;
        maxHeapify(maxHeap, n, 1);
    }
    printf("%d\n", meat);
    return 0;
}