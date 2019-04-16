#include<stdio.h>

int maximum(int arr[], int n)
{
    int max = 0;
    for(int i=0;i<n;i++)
    {
        if(arr[i] > arr[max])
        {
            max = i;
        }
    }
    return max;
}

int minimum(int arr[], int n)
{
    int min = 0;
    for(int i=0;i<n;i++)
    {
        if(arr[i] < arr[min])
        {
            min = i;
        }
    }
    return min;
}

int count(int arr[], int n, int elem)
{
    int c = 0;
    for(int i=0;i<n;i++)
    {
        if(arr[i] == elem)
        {
            c++;
        }
    }
    return c;
}

int main()
{
    int q;
    scanf("%d", &q);

    int arr[q], ans[q], size = 0, index = 0;
    char str[20];
    while(q--)
    {
        scanf("%s", str);
        if(str[0] == 'P')
        {
            scanf("%d", &arr[size++]);
        }
        else
        {
            if(size == 0)
            {
                ans[index++] = -1;
                continue;
            }
            if(str[0] == 'D')
            {
                int maxIndex = maximum(arr, size);
                int minIndex = minimum(arr, size);
                int a = arr[maxIndex];
                int b = arr[minIndex];
                ans[index++] = arr[maxIndex] - arr[minIndex];
                arr[maxIndex] = arr[--size];
                if(a != b)
                {
                    if(minIndex == size)
                    {
                        minIndex = maxIndex;
                    }
                    arr[minIndex] = arr[--size];
                }
            }
            else
            {
                int x;
                if(str[5] == 'H')
                {
                    x = maximum(arr, size);
                }
                else
                {
                    x = minimum(arr, size);
                }
                ans[index++] = count(arr, size, arr[x]);
            }
        }
    }
    for(int i=0;i<index;i++)
    {
        printf("%d\n", ans[i]);
    }
    return 0;
}