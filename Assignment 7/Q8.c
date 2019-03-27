#include<stdio.h>

int abs(int x)
{
    return x>0?x:-x;
}

int satisfiesAdjacentOne(int n)
{
    if(n<10)
    {
        return 1;
    }
    while(n>=10)
    {
        int last = n%10;
        n/=10;
        int next = n%10;
        if(abs(last-next) != 1)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0;i<n;i++)
    {
        if(satisfiesAdjacentOne(i))
        {
            printf("%d ", i);
        }
    }
    if(n>0)
    {
        printf("\n");
    }
} 