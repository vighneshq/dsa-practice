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

void insertMaxHeap(int maxHeap[], int* size, int elem)
{
    *size += 1;
    int index = *size;
    maxHeap[index] = elem;
    while(index > 1 && maxHeap[index/2] < maxHeap[index])
    {
        swap(&maxHeap[index/2], &maxHeap[index]);
        index /= 2;
    }
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    int maxHeap[n+1], index = 0, elem;
    for(int i=0;i<n;i++)
    {
        scanf("%d", &elem);
        insertMaxHeap(maxHeap, &index, elem); 
    }

    int meat = 0;
    while(k--)
    {
        meat += maxHeap[1];
        maxHeap[1] /= 2;
        maxHeapify(maxHeap, index, 1);
    }
    printf("%d\n", meat);
    return 0;
}