#include<stdio.h>

int max(int a, int b)
{
    return a>b?a:b;
}

int main()
{
    int n, m, x;
    scanf("%d %d %d", &n, &m, &x);

    int a[n], b[m];
    for(int i=0;i<n;i++)
    {
        scanf("%d", &a[i]);
    }
    for(int i=0;i<m;i++)
    {
        scanf("%d", &b[i]);
    }

    int i = 0, sum = 0, j = 0;
    while(i < n && sum + a[i] <= x)
    {
        sum += a[i];
        i++;
    }
    int count = i;
    while(j < m)
    {
        sum += b[j];
        j++;
        while(sum > x && i > 0)
        {
            i--;
            sum -= a[i];
        }
        if(sum <= x)
        {
            count = max(count, i+j);
        }
    }
    printf("%d\n", count);
    return 0;
}