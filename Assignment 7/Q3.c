#include<stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
    }
    
    int count = 0, root = -1;
    for(int i=0;i<n;i++)
    {
        if(arr[i] == i+1)
        {
            count++;
            if(root != -1)
            {
                arr[i] = root;
            }
            root = i + 1;
        }
    }
    printf("%d\n", count-1);
    for(int i=0;i<n;i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");   
}