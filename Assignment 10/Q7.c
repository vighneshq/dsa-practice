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
    
    int count = 0;
    for(int i=0;i<n;i++)
    {
        int ones = 0;
        for(int j=i;j<n;j++)
        {
            ones += arr[j];
            if(2*ones == j - i + 1)
            {
                count++;
            }
        }
    }
    printf("%d\n", count);
    return 0;
}