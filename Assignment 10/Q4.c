#include<stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n+1];
    for(int i=1;i<=n;i++)
    {
        scanf("%d", &arr[i]);
    }

    int isMinHeap = 1;
    for(int i=2;i<=n;i++)
    {
        if(arr[i] < arr[i/2])
        {
            isMinHeap = 0;
            break;
        }
    }
    
    if(isMinHeap)
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }
}