#include<stdio.h>

int min(int a, int b)
{
    return a<b?a:b;
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    int arr[n];
    char c;
    scanf("%c", &c);
    for(int i=0;i<n;i++)
    {
        scanf("%c", &c);
        if(c == 'R')
        {
            arr[i] = 0;
        }
        else if(c == 'Y')
        {
            arr[i] = 1;
        }
        else
        {
            arr[i] = 2;
        }
        scanf("%c", &c);
    }
    int count = 0;
    for(int i=0;i<n;i++)
    {
        if(arr[i] == 2)
        {
            continue;
        }
        else 
        {   
            int shift = 2 - arr[i];
            int lim = min(i+k,n);
            for(int j=i;j<lim;j++)
            {
                arr[j] = (arr[j] + shift)%3;
            }
            count += shift;
        }
    }
    printf("%d\n", count);
    return 0;
}
