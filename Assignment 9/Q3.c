#include<stdio.h>

int min(int a, int b)
{
    return a<b?a:b;
}

int main()
{
    const int MAX = 1E6;
    int ans[MAX+1];
    
    // T(n) = O(nlgn) 
    for(int i=0;i<=MAX;i++)
    {
        ans[i] = -1;
    }
    ans[0] = 0, ans[1] = 1, ans[2] = 2, ans[3] = 3;
    for(int i=0;i<=MAX;i++)
    {
        if(ans[i] == -1 || ans[i] > ans[i-1] + 1)
        {
            ans[i] = ans[i-1] + 1;
        }
        for(int j=1;j<=i && j*i <= MAX;j++)
        {
            if(ans[j*i] == -1 || ans[j*i] > ans[i] + 1)
            {
                ans[j*i] = ans[i] + 1;
            }
        }
    }
    // T(n) = O(n^(3/2))
    // for(int i=4;i<=MAX;i++)
    // {
    //     ans[i] = 1 + ans[i-1];
    //     for(int j=2;j*j<=i;j++)
    //     {
    //         if(i%j == 0)
    //         {
    //             ans[i] = min(ans[i], 1 + ans[i/j]);
    //         }
    //     }
    // }

    int q;
    scanf("%d", &q);
    while(q--)
    {
        int n;
        scanf("%d", &n);
        printf("%d\n", ans[n]);
    }
    return 0;
}