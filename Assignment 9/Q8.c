#include<stdio.h>

typedef struct
{
    int p, c;
} Project;

void swap(Project* a, Project* b)
{
    Project p = *a;
    *a = *b;
    *b = p;
}

void merge(Project a[], int l, int m, int h)
{
    int p = m - l + 1;
    int q = h - m;

    Project L[p], R[q];
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
        if(L[i].c > R[j].c)
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

void mergesort(Project a[], int l, int r)
{
    if(l<r)
    {
        int m = (l+r)/2;
        mergesort(a,l,m);
        mergesort(a,m+1,r);
        merge(a,l,m,r);
    }
}

void maxHeapify(Project maxHeap[], int size, int i)
{
    int l = 2*i;
    int r = 2*i + 1;
    int index = i;
    if(l<=size && maxHeap[l].p > maxHeap[index].p)
    {
        index = l;
    }
    if(r<=size && maxHeap[r].p > maxHeap[index].p)
    {
        index = r;
    }
    if(index != i)
    {
        swap(&maxHeap[i], &maxHeap[index]);
        maxHeapify(maxHeap, size, index);
    }
}

void insertmaxHeap(Project maxHeap[], int *size, Project elem)
{
    (*size) += 1;
    int index = (*size);
    maxHeap[index] = elem;
    while(index > 1 && (maxHeap[index].p > maxHeap[index/2].p))
    {
        swap(&maxHeap[index], &maxHeap[index/2]);
        index /= 2;
    }
}

int main()
{
    int k, w, n;
    scanf("%d\n%d\n%d", &k, &w, &n);

    Project p[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d", &p[i].p);
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d", &p[i].c);
    }
    
    mergesort(p, 0, n-1);
    
    Project maxHeap[n+1];
    int index = 0, enqueued = 0, done = 0, capital = w;
    while(done < k)
    {   
        if(index != 0)
        {
            Project toDo = maxHeap[1];
            capital += toDo.p;
            swap(&maxHeap[1], &maxHeap[index]);
            index--;
            maxHeapify(maxHeap, index, 1);
            done++;
        }
        int prev = enqueued;
        while(enqueued < n && p[enqueued].c <= capital)
        {
            insertmaxHeap(maxHeap, &index, p[enqueued]);
            enqueued++;
        }
        if(prev == enqueued && index == 0)
        {
            break;
        }
    }
    printf("%d\n", capital);
    return 0;
}