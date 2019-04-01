#include<stdio.h>

void swap(int* a, int* b)
{
    int p = *a;
    *a = *b;
    *b = p;
}

void minHeapify(int minHeap[], int size, int i)
{
    int l = 2*i;
    int r = 2*i + 1;
    int index = i;
    if(l<=size && minHeap[l] < minHeap[index])
    {
        index = l;
    }
    if(r<=size && minHeap[r] < minHeap[index])
    {
        index = r;
    }
    if(index != i)
    {
        swap(&minHeap[i], &minHeap[index]);
        minHeapify(minHeap, size, index);
    }
}

void insertMinHeap(int minHeap[], int *size, int elem)
{
    (*size) += 1;
    int index = (*size);
    minHeap[index] = elem;
    while(index > 1 && (minHeap[index] < minHeap[index/2]))
    {
        swap(&minHeap[index], &minHeap[index/2]);
        index /= 2;
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
    }

    int minHeap[n+1];
    int index = 0;

    int sum = 0;
    for(int i=0;i<n;i++)
    {
        if(index != 0 && minHeap[1] < arr[i])
        {
            sum += arr[i] - minHeap[1];
            // swap(&minHeap[1], &minHeap[index]);
            // index--;
            minHeap[1] = arr[i];
            minHeapify(minHeap, index, 1);
        }
        else
        {
            insertMinHeap(minHeap, &index, arr[i]);
        }
    }
    printf("%d\n", sum);
}
