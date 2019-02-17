#include<stdio.h>
#include<stdlib.h>

void insert(int* arr, int elem, int *size, int *m)
{
    if((*size) == (*m))
    {
        (*m) = (*m)*2;
        arr = realloc(arr, (*m)*sizeof(int));
    }
    int pos;
    for(pos = 0;pos<(*size);pos++)
    {
        if(arr[pos] > elem)
        {
            break;
        }
    }
    for(int i = (*size)-1;i>=pos;i--)
    {
        arr[i+1] = arr[i];
    }
    (*size)++;
    arr[pos] = elem;
}

void delete(int* arr, int elem, int* size)
{
    if((*size) > 0)
    {
        int pos = 0;
        while(arr[pos] != elem)
        {
            pos++;
        }
        pos++;
        while(pos < (*size))
        {
            arr[pos-1] = arr[pos];
            pos++;
        }
        (*size)--;
    }
}

int swap(int *arr, int x, int y, int size)
{
    if(size > 0)
    {
         int xpos = 0;
        while(arr[xpos] != x)
        {
            xpos++;
        }

        int ypos = 0;
        while(arr[ypos] != y)
        {
            ypos++;
        }

        arr[ypos] = x;
        arr[xpos] = y;
    }
}

void merge(int *arr, int p, int q, int r)
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

void mergesort(int *arr, int l, int r)
{
    if(l < r)
    {
        int m = (l+r)/2;
        mergesort(arr, l, m);
        mergesort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

void printArr(int* arr, int size)
{
    if(size > 0)
    {
        for(int i=0;i<size;i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

int main()
{
    int m;
    scanf("%d", &m);

    int* arr = malloc(m*sizeof(int));
    for(int i=0;i<m;i++)
    {
        scanf("%d", &arr[i]);
    }

    int N;
    scanf("%d", &N);
    int size = m;
    while(N--)
    {
        char op[3];
        scanf("%s", op);
        if(op[0] == 'I')
        {
            int elem;
            scanf("%d", &elem);
            insert(arr, elem, &size, &m);
        }
        else if(op[0] == 'D')
        {
            int elem;
            scanf("%d", &elem);
            delete(arr, elem, &size);
        }
        else if(op[0] == 'S' && op[1] == 'W')
        {
            int x, y;
            scanf("%d %d", &x, &y);
            swap(arr, x, y, size);
        }
        else
        {
            mergesort(arr, 0, size-1);
        }
        printArr(arr, size);
    }
    return 0;
}