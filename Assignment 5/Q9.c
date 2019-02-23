#include<stdio.h>
#include<limits.h>

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
        if(L[i] < R[j])
        {
            arr[k++] = L[i++];
        }
        else
        {
            arr[k++] = R[j++];
        }
    }

    if(i == n)
    {
        while(j < m)
        {
            arr[k++] = R[j++];
        }
    }
    else
    {
        while(i < n)
        {
            arr[k++] = L[i++];
        }   
    }
}

void mergesort(int arr[], int l, int r)
{
    if(l < r)
    {
        int m = (l+r)/2;
        mergesort(arr, l, m);
        mergesort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

int findRight(int arr[], int n, int elem)
{
    int l = 0;
    int h = n - 1;
    int pos;
    while(l<=h)
    {
        pos = (l+h)/2;
        if((pos == n - 1 || arr[pos+1]>elem) && arr[pos] == elem)
        {
            break;
        } 
        else if(arr[pos]>elem)
        {
            h = pos - 1;
        }
        else
        {
            l = pos + 1;
        }
    }
    return (arr[pos] == elem)?pos:-1;
}

int helperLeft(int arr[], int n, int elem)
{
    int l = 0;
    int h = n - 1;
    int pos;
    while(l<=h)
    {
        pos = (l+h)/2;
        if((pos == 0 || arr[pos-1]<elem) && arr[pos] == elem)
        {
            break;
        } 
        else if(arr[pos]<elem)
        {
            l = pos + 1;
        }
        else
        {
            h = pos - 1;
        }
    }
    return (arr[pos] == elem)?pos:-1;
}

int findLeft(int arr[], int n, int elem)
{
    if(elem > arr[n-1])
    {
        return helperLeft(arr, n,arr[n-1]);
    }
    int pos = helperLeft(arr,n,elem);
    if(pos != -1)
    {
        return pos;
    }
    int l = 0;
    int h = n-1;
    while(l<=h)
    {
        pos = (l+h)/2;
        if(l == h)
        {
            break;
        }
        if(arr[pos] <= elem)
        {
            l = pos + 1;
        }
        else
        {
            h = pos;
        }
    }
    return pos;
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
    mergesort(arr, 0, n-1);

    if(arr[0] == arr[n-1])
    {
        printf("%d\n", n-1);
        return 0;
    }
    int min = INT_MAX;
    int l = 0;
    while(l<n)
    {
        int elem = arr[l];
        int lower = findRight(arr,n,elem);
        int higher = findLeft(arr,n,2*elem);
        int count;
        if(arr[higher] <= 2*elem)
        {
            count = lower + n - 1 - higher;
        }
        else
        {
            count = lower + n - higher;
        }
        min = (min<count)?min:count;
        l = lower + 1;
    }    
    printf("%d\n", min);
    return 0;
}
