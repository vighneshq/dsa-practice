#include<stdio.h>

typedef struct
{
    int s, len;
} Interval;

void swap(Interval* a, Interval* b)
{
    Interval p = *a;
    *a = *b;
    *b = p;
}

void maxHeapify(Interval maxHeap[], int size, int i)
{
    int l = 2*i;
    int r = 2*i + 1;
    int index = i;
    if(l<=size)
    {
        if(maxHeap[l].len > maxHeap[index].len)
        {
            index = l;
        }
        else if((maxHeap[l].len == maxHeap[index].len) && (maxHeap[l].s < maxHeap[index].s))
        {
            index = l;
        }
    }
    if(r<=size)
    {
        if(maxHeap[r].len > maxHeap[index].len)
        {
            index = l;
        }
        else if((maxHeap[r].len == maxHeap[index].len) && (maxHeap[r].s < maxHeap[index].s))
        {
            index = l;
        }
    }
    if(index != i)
    {
        swap(&maxHeap[i], &maxHeap[index]);
        maxHeapify(maxHeap, size, index);
    }
}

void insertMaxHeap(Interval maxHeap[], int *size, Interval elem)
{
    (*size) += 1;
    int index = (*size);
    maxHeap[index] = elem;
    while(index > 1 && (maxHeap[index].len > maxHeap[index/2].len))
    {
        swap(&maxHeap[index], &maxHeap[index/2]);
        index /= 2;
    }
}

Interval removeMax(Interval maxHeap[], int *size)
{
    Interval max = maxHeap[1];
    swap(&maxHeap[1], &maxHeap[*size]);
    *size -= 1;
    maxHeapify(maxHeap, *size, 1);
    return max;
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    char pref[k];
    scanf("%s", pref);

    int chairs[n+1];
    for(int i=1;i<=n;i++)
    {
        chairs[i] = -1;
    }

    Interval maxHeap[n+1], begin = {1, n};
    int index = 0;
    insertMaxHeap(maxHeap, &index, begin);

    for(int i=1;i<=k;i++)
    {
        Interval top = removeMax(maxHeap, &index);
        int pos = top.s + (top.len-1)/2;
        if((top.len%2 == 0) && (pref[i-1] == 'R'))
        {
            pos += 1;
        }
        chairs[pos] = i;
        Interval lower = {top.s, pos-top.s};
        Interval upper = {pos+1, top.len-lower.len-1};    

        printf("%d | %d %d | %d %d --\n", pos, lower.s, lower.len, upper.s, upper.len);
        if(lower.s >= 1 && lower.len != 0)
        {
            insertMaxHeap(maxHeap, &index, lower);
        }
        if(upper.s <= n && upper.len != 0)
        {
            insertMaxHeap(maxHeap, &index, upper);
        }
    }

    int q, num;
    scanf("%d", &q);
    while(q--)
    {
        scanf("%d", &num);
        printf("%d\n", chairs[num]);
    }
    return 0;
}