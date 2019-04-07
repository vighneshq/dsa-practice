#include<stdio.h>
#include<stdlib.h>

int indexable(int i, int j, int n)
{
    return (0<=i && i <n-1) && (0<= j && j<n-1);
}

void dfs(int adj[], int n, int i, int j, int t, int vis[])
{
    vis[i*n+j] = 1;
    int l[4] = {-1, 0, 1, 0};
    int r[4] = {0, -1, 0, 1};
    for(int x=0;x<4;x++)
    {
        int row = i+l[x];
        int col = j+r[x];
        if(!vis[row*n+col] && adj[row*n+col] <= t)
        {
            dfs(adj, n, row, col, t, vis);
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    int adj[n*n], m = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d", &adj[i*n+j]);
            m = (m>adj[i*n+j])?m:adj[i*n+j];
        }
    }
    int l = 0, h = m, ans = m;
    while(l<h)
    {
        int t = (l+h)/2;
        int vis[n*n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                vis[i*n+j] = 0;
            }
        }
        dfs(adj, n, 0, 0, t, vis);
        if(vis[n*n-1])
        {
            ans = t;
            h = t - 1;
        }
        else
        {
            l = t + 1;
        }
    }
    printf("%d\n", ans);
}