#include<stdio.h>

void merge(int arr[], int p, int q, int r)
{
    int n = q - p + 1;
    int m = r - q;

    int L[n], R[m];
    for(int i=0;i<n;i++)
    {
        L[i] = arr[p+i];
    }
    for(int j=0;j<m;j++)
    {
        R[j] = arr[q+1+j];
    }

    int i = 0, j = 0, k = p;
    while(i < n && j < m)
    {
        if(L[i] <= R[j])
        {
            arr[k++] = L[i++];
        }
        else
        {
            arr[k++] = R[j++];
        }
    }
    while(i < n)
    {
        arr[k++] = L[i++];
    }
    while(j < m)
    {
        arr[k++] = R[j++];
    }
}

void mergesort(int arr[], int l, int r)
{
    if(l < r)
    {
        int m = (l+r)/2;
        mergesort(arr,l,m);
        mergesort(arr,m+1,l);
        merge(arr,l,m,r);
    }
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
    }
    mergesort(arr, 0, n - 1);
    int max = arr[n-1];
    int count = 0;
    for(int i=n-1;i>=0;i--)
    {
        if(arr[i] >= max)
        {
            count += arr[i] - 1;
            max--; 
        }
        else if(arr[i] < max)
        {
            count += arr[i] - 1 - (max - arr[i]) ;
            max = arr[i] - 1;
        }
    }
    if(arr[0] != 1)
    {
        count = count - (arr[0] - 1);
    }
    printf("%d\n", count);
    return 0;
}