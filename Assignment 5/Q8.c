#include<stdio.h>

void swap(int arr[], int type [], int x, int y)
{
    int t = arr[x];
    arr[x] = arr[y];
    arr[y] = t;

    t = type[x];
    type[x] = type[y];
    type[y] = t;
}

int bubblesort(int arr[], int type[], int n)
{
    for(int i=0;i<n;i++)
    {
        int swapped = 0;
        for(int j=0;j<n-1-i;j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(arr, type, j, j + 1);
                swapped = 1;
            }
        }
        if(!swapped)
        {
            break;
        }
    }
}

int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    int n;
    scanf("%d", &n);
    int arr[n], type[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
        char str[5];
        scanf("%s", str);
        type[i] = (str[0] == 'P')?1:2;
    }
    bubblesort(arr, type, n);
    
    int m = a + b + c, cost = 0;
    for(int i=0;i<n;i++)
    {
        if(type[i] == 1)
        {
            if(a > 0)
            {
                a--;
                cost += arr[i];
            }
            else if(c>0)
            {
                c--;
                cost +=arr[i];
            }
        }
        else if(type[i] == 2)
        {
            if(b > 0)
            {
                b--;
                cost += arr[i];
            }
            else if(c>0)
            {
                c--;
                cost +=arr[i];
            }
        }
    }
    printf("%d %d\n", m - (a+b+c), cost);
}