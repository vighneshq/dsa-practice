#include<stdio.h>
#include<stdlib.h>

int n, k, s, t;
int ans = -1;

void func(int price, int capacity, int time, int fuel, int pos, int gas[])
{
    if(fuel < 0 || pos > s || time > t || (ans != -1 && price > ans))
    {
        return;
    }
    if(pos == s && time <= t)
    {
        if(price < ans || ans == -1)
        {
            ans = price;
        }
        return;
    }
    else
    {
        if(gas[pos] == 1)
        {
            fuel = capacity;
        }
        func(price, capacity, time+1,fuel-2,pos+1, gas);
        func(price, capacity, time+2,fuel-1,pos+1, gas);
    }
}

int main()
{
    scanf("%d %d %d %d", &n, &k, &s, &t);

    int c[n], v[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d %d", &c[i], &v[i]);
    }

    int pos[k];
    for(int i=0;i<k;i++)
    {
        scanf("%d", &pos[i]);
    }  
    int* gas = calloc(s+1, sizeof(int));
    for(int i=0;i<k;i++)
    {
        gas[pos[i]] = 1;
    }

    for(int i=0;i<n;i++)
    {
        func(c[i],v[i],0,v[i],0,gas);
    }
    printf("%d\n", ans);
    return 0;
}