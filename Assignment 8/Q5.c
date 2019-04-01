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
    while(i<n && j<m)
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

    while(i<n)
    {
        arr[k++] = L[i++];
    }

    while(j<m)
    {
        arr[k++] = R[j++];
    }
}

void mergesort(int arr[], int l, int r)
{
    if(l<r)
    {
        int m = (l+r)/2;
        mergesort(arr,l,m);
        mergesort(arr,m+1,r);
        merge(arr,l,m,r);
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
    mergesort(arr, 0, n-1);
    int zeros = 0;
    while(arr[zeros] == 0)
    {
        zeros++;
    }
    
    if(zeros == n)
    {
        printf("0\n");
    }
    else if(zeros == n - 1)
    {
        printf("%d\n", arr[zeros]);
    }
    else
    {
        if(zeros != 0)
        {
            arr[0] = arr[zeros];
            arr[1] = arr[zeros+1];
            arr[zeros] = arr[zeros+1] = 0;
        }
        int num1 = 0, num2 = 0;
        int i = 0, j = 1;
        while(i < n)
        {
            num1 = num1*10+arr[i];
            i+=2;
        }
        while(j<n)
        {
            num2 = num2*10+arr[j];
            j+=2;
        }
        printf("%d\n", num1+num2);
    }    
    return 0;
}