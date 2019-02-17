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
        if(L[i] >= R[j])
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

void mergesortDesc(int arr[], int l, int r)
{
    if(l < r)
    {
        int m = (l+r)/2;
        mergesortDesc(arr, l, m);
        mergesortDesc(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

void printNum(int arr[], int n)
{
    if(n > 0)
    {
        int num = 0;
        for(int i=0;i<n;i++)
        {
            num = num*10 + arr[i];
        }
        printf("%d\n", num);
        return;
    }
    printf("No such number.\n");
}

void fillArr(int arr[], int n, int r0[], int z, int r1[], int o, int r2[], int t)
{
    for(int i=0;i<z;i++)
    {
        arr[i] = r0[i];
    }
    for(int i=0;i<o;i++)
    {
        arr[z+i] = r1[i];
    }
    for(int i=0;i<t;i++)
    {
        arr[z+o+i] = r2[i];
    }
    mergesortDesc(arr, 0, n - 1);
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n], remainder = 0;
    for(int i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
        remainder += arr[i];
    }
    remainder = remainder%3;
    mergesortDesc(arr, 0, n - 1);

    if(remainder == 0)
    {
        printNum(arr, n);
    }
    else
    {
        int r0[n], r1[n], r2[n];
        int z = 0, o = 0, t = 0;
        for(int i=0;i<n;i++)
        {
            switch(arr[i]%3)
            {
                case 0:
                    r0[z++] = arr[i];
                    break;
                case 1:
                    r1[o++] = arr[i];
                    break;
                case 2:
                    r2[t++] = arr[i];
                    break;
            }
        }
        if(remainder == 1)
        {
            if(o > 0)
            {
                o--;
                n--;
            }
            else if(t > 1)
            {
                t-=2;
                n-=2;
            }
            else
            {
                n = 0;
            }
        }
        else
        {
             if(t > 0)
            {
                t--;
                n--;
            }
            else if(o > 1)
            {
                o-=2;
                n-=2;
            }
            else
            {
                n = 0;
            }
        }
        fillArr(arr, n, r0, z, r1, o, r2, t);
        printNum(arr, n);
    }
    return 0;
}