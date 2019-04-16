#include<stdio.h>
#include<string.h>
#include<limits.h>

void merge(int a[], int l, int m, int h)
{
    int p = m - l + 1;
    int q = h - m;

    int L[p], R[q];
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
        if(L[i] >= R[j])
        {
            a[k++] = L[i++];
        }
        else
        {
            a[k++] = R[j++];
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

void mergeSort(int a[], int l, int h)
{
    if(l<h)
    {;
        int m = (l+h)/2;
        mergeSort(a,l,m);
        mergeSort(a,m+1,h);
        merge(a,l,m,h);
    }
}


int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    int right[n], left[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d", &right[i]);
    }
    for(int j=0;j<n;j++)
    {
        scanf("%d", &left[j]);
    }
    mergeSort(right, 0, n - 1);
    mergeSort(left, 0, n - 1);

    int index[n];
    memset(index, 0, n*sizeof(int));
    while(k--)
    {
        int max_sum = INT_MAX;
        int max_index = -1;
        for(int i=0;i<n;i++)
        {
            if(index[i] < n)
            {
                if(max_index == -1 || left[i] + right[index[i]] > max_sum)
                {
                    max_sum = left[i] + right[index[i]];
                    max_index = i;
                }
            }
        }
        if(max_index != -1)
        {
            printf("%d ", max_sum);
            index[max_index]++;
        }
    }
    printf("\n");
    return 0;
}