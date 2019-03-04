#include<stdio.h>

long long int max(long long int a, long long int b)
{
    return a>b?a:b;
}

void maxAs(long long int a[], int n)
{
    for(int i=1;i<=6;i++)
    {
        a[i] = i;
    }
    for(int i=7;i<=n;i++)
    {
        long long int x = max(2*a[i-3], 3*a[i-4]);
        long long int y = max(4*a[i-5], 5*a[i-6]);
        a[i] = max(x,y);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    if(n > 75)
    {
        printf("%d\n", -1);
        return 0;
    }
    long long int a[76];
    maxAs(a,n);
    printf("%d\n", a[n]);
    return 0;
}