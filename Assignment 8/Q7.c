#include<stdio.h>
#include<limits.h>

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
    }

    int sum = 0;
    for(int i=0;i<n;i++)
    {
        int min = arr[i];
        for(int l = i;l<n;l++)
        {
            min = (min<arr[l])?min:arr[l];
            sum += min;
        }
    }
    printf("%d\n", sum);
    return 0;
}