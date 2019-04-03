#include<stdio.h>

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(int minHeap[], int size, int i)
{
    int l = 2*i;
    int r = 2*i+1;
    int index = i;
    if(l <= size && minHeap[l] < minHeap[index])
    {
        index = l;
    }
    if(r <= size && minHeap[r] < minHeap[index])
    {
        index = r;
    }
    if(index != i)
    {
        swap(&minHeap[i], &minHeap[index]);
        minHeapify(minHeap, size, index);
    }
}

void insertMinHeap(int minHeap[], int* size, int elem)
{
    *size += 1;
    int index = *size;
    minHeap[index] = elem;
    while(index > 1 && minHeap[index/2] > minHeap[index])
    {
        swap(&minHeap[index/2], &minHeap[index]);
        index /= 2;
    }
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
    int n;
    scanf("%d", &n);

    int maxHeap[n+1], minHeap[n+1], maxIndex = 0, minIndex = 0, elem;
    double medians[n+1];
    medians[0] = 0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d", &elem);
        if(minIndex == maxIndex)
        {
            if(elem > medians[i-1])
            {
                insertMinHeap(minHeap, &minIndex, elem);
                medians[i] = minHeap[1];
            }
            else
            {
                insertMaxHeap(maxHeap, &maxIndex, elem);
                medians[i] = maxHeap[1]; 
            }
        }
        else if(minIndex > maxIndex)
        {
            if(elem > medians[i-1])
            {
                int temp = minHeap[1];
                minHeap[1] = minHeap[minIndex];
                minIndex--;
                minHeapify(minHeap, minIndex, 1);
                insertMaxHeap(maxHeap, &maxIndex, temp);
                insertMinHeap(minHeap, &minIndex, elem);
            }
            else
            {
                insertMaxHeap(maxHeap, &maxIndex, elem);
            }
            medians[i] = (maxHeap[1] + minHeap[1])/2.0;
        }
        else
        {
            if(elem < medians[i-1])
            {
                int temp = maxHeap[1];
                maxHeap[1] = maxHeap[maxIndex];
                maxIndex--;
                maxHeapify(maxHeap, maxIndex, 1);
                insertMinHeap(minHeap, &minIndex, temp);
                insertMaxHeap(maxHeap, &maxIndex, elem);
            }
            else
            {
                insertMinHeap(minHeap, &minIndex, elem);
            }
            medians[i] = (maxHeap[1] + minHeap[1])/2.0;
        }
    }
    for(int i=1;i<=n;i++)
    {
        printf("%f ", medians[i]);
    }
    printf("\n");
    return 0;
}