#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    int l, r;
} Range;

int overlap(Range a, Range b)
{
    if(a.l <= b.r && a.r >= b.l)
    {
        return 1;
    }
    return 0;
}

int min(int a, int b)
{
    return (a<b)?a:b;
}

int max(int a, int b)
{
    return (a>b)?a:b;
}

void printGroups(int* group, int n)
{
    for(int i=0;i<n;i++)
    {
        if(group[i] == 1)
        {
            printf("IM ");
        }
        else
        { 
            printf("CA ");
        }
    }
    printf("\n");
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n;
        scanf("%d", &n);
        Range arr[n];
        for(int i=0;i<n;i++)
        {
            scanf("%d %d", &arr[i].l, &arr[i].r);
        }

        int* group = calloc(n, sizeof(int));
        group[0] = 1;
        Range temp = {arr[0].l, arr[0].r};
        int count = 0;
        for(int i=0;i<n;i++)
        {
            if(overlap(temp, arr[i]))
            {
                count++;
                group[i] = 1;
                temp.l = min(temp.l, arr[i].l);
                temp.r = max(temp.r, arr[i].r);
            }
        }
        if(count == n)
        {
            printf("%d\n", -1);
        }
        else if(count > 1)
        {
            printGroups(group,n);
        }
        else
        {
            int start = 0;
            while(start < n)
            {
                if(group[start] == 0)
                {
                    break;
                }
                start++;
            }
            Range temp = {arr[start].l, arr[start].r};
            count = 0;
            for(int i=start;i<n;i++)
            {
                if(overlap(temp, arr[i]))
                {
                    count++;
                    group[i] = 2;
                    temp.l = min(temp.l, arr[i].l);
                    temp.r = max(temp.r, arr[i].r);
                }
            }
            if(count > 1)
            {
                printGroups(group, n);
            }
            else
            {
                group[1] = 1;
                printGroups(group,n);
            }
        }
    }
    return 0;  
}