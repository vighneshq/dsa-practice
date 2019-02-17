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

    int i = 0, j = 0;
    int k = p;
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
        mergesort(arr, l, m);
        mergesort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

int first(int arr[], int low, int high, int x, int n) 
{ 
    if (high >= low) 
    { 
        int mid = (low+high)/2; 
        if ((mid == 0 || x > arr[mid-1]) && arr[mid] == x) 
        {
            return mid; 
        }
        if (x > arr[mid])
        {
            return first(arr, (mid + 1), high, x, n); 
        }
        return first(arr, low, (mid -1), x, n); 
    } 
    return -1; 
} 

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int a1[n], a2[m], temp[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d", &a1[i]);
        temp[i] = a1[i];
    }
    for(int i=0;i<m;i++)
    {
        scanf("%d", &a2[i]);
    }
    mergesort(temp, 0, n-1);
    
    int vis[n];
    for(int i=0;i<n;i++)
    {
        vis[i] = 0;
    }
    int index = 0;
    for(int i=0;i<m;i++)
    {
        int pos = first(temp, 0, n-1, a2[i], n);
        if(pos == -1)
        {
            continue;
        }
        for(int j=pos;j<n;j++)
        {
            if(temp[j] != a2[i])
            {
                break;
            }
            a1[index++] = temp[j];
            vis[j] = 1;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            a1[index++] = temp[i];
        }
    }

    for(int i=0;i<n;i++)
    {
        printf("%d ", a1[i]);
    }
    printf("\n");
}