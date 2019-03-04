#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int main()
{
    int n, m, sort;
    scanf("%d %d %d", &n, &m, &sort);
    int arr[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    int id = 0;
    int lim = (m*(m-1))/2;

    int a[lim], b[lim];
    if(sort == 0)
    {
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<m;i++)
            {
                int min = i;
                for(int j=i+1;j<m;j++)
                {
                    if(arr[k][j] < arr[k][min])
                    {
                        min = j;
                    }
                }
                if(arr[k][min] < arr[k][i])
                {
                    swap(&arr[k][i], &arr[k][min]);
                    a[id] = i;
                    b[id] = min;
                    id++;
                }
            }
            for(int i=k+1;i<n;i++)
            {
                for(int j=0;j<id;j++)
                {
                    int x = a[j];
                    int y = b[j];
                    if( x < y && arr[i][x] > arr[i][y])
                    {
                        swap(&arr[i][x], & arr[i][y]);
                    }
                }
            }
        }
    }
    else
    {
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<m;i++)
            {
                int max = i;
                for(int j=i+1;j<m;j++)
                {
                    if(arr[k][j] > arr[k][max])
                    {
                        max = j;
                    }
                }
                if(arr[k][max] > arr[k][i])
                {
                    swap(&arr[k][i], &arr[k][max]);
                    a[id] = i;
                    b[id] = max;
                    id++;
                }
            }
            for(int i=k+1;i<n;i++)
            {
                for(int j=0;j<id;j++)
                {
                    int x = a[j];
                    int y = b[j];
                    if( x < y && arr[i][x] < arr[i][y])
                    {
                        swap(&arr[i][x], & arr[i][y]);
                    }
                }
            }
        }
    }
    printf("%d\n", id);
    for(int i=0;i<id;i++)
    {
        printf("%d %d\n", a[i]+1,b[i]+1);
    }
    return 0;
}