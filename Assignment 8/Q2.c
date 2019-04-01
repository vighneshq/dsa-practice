#include<stdio.h>

typedef struct
{
    int t, s;
} Process;

void merge(Process a[], int l, int m, int h)
{
    int p = m - l + 1;
    int q = h - m;

    Process L[p], R[q];
    for(int i=0;i<p;i++)
    {
        L[i] = a[l+i];
    }
    for(int j=0;j<q;j++)
    {
        R[j] = a[m+j+1];
    }

    int i = 0, j = 0, k = l;
    while(i<p && j<q)
    {
        if(L[i].t > R[j].t)
        {
            a[k++] = R[j++];
        }
        else
        {
            a[k++] = L[i++];
        }
    }
    while(i<p)
    {
        a[k++] = L[i++];
    }
    while(j<q)
    {
        a[k++] = R[j++];
    }
}

void swap(Process* a, Process* b)
{
    Process p = *a;
    *a = *b;
    *b = p;
}

void mergesort(Process a[], int l, int r)
{
    if(l<r)
    {
        int m = (l+r)/2;
        mergesort(a,l,m);
        mergesort(a,m+1,r);
        merge(a,l,m,r);
    }
}

void minHeapify(Process minHeap[], int size, int i)
{
    int l = 2*i;
    int r = 2*i + 1;
    int index = i;
    if(l<=size && minHeap[l].s < minHeap[index].s)
    {
        index = l;
    }
    if(r<=size && minHeap[r].s < minHeap[index].s)
    {
        index = r;
    }
    if(index != i)
    {
        swap(&minHeap[i], &minHeap[index]);
        minHeapify(minHeap, size, index);
    }
}

void insertMinHeap(Process minHeap[], int *size, Process elem)
{
    (*size) += 1;
    int index = (*size);
    minHeap[index] = elem;
    while(index > 1 && (minHeap[index].s < minHeap[index/2].s))
    {
        swap(&minHeap[index], &minHeap[index/2]);
        index /= 2;
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    Process p[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d %d", &p[i].t, &p[i].s);
    }
    mergesort(p, 0, n-1);

    Process minHeap[n+1];
    int index = 0, waitingTime = 0, currentTime = 0, enqueued = 0;

    while(index > 0 || enqueued < n)
    {   
        if(index != 0)
        {
            Process current = minHeap[1];
            currentTime += current.s;
            waitingTime += currentTime - current.t;
            swap(&minHeap[1], &minHeap[index]);
            index--;
            minHeapify(minHeap, index, 1);
            
        }
        else
        {
            currentTime = p[enqueued].t;
        }
        while(enqueued < n && p[enqueued].t <= currentTime)
        {
            insertMinHeap(minHeap, &index, p[enqueued]);
            enqueued++;
        }
    }
    printf("%f\n", waitingTime/(double)n);
}