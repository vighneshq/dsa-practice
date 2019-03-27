#include<stdio.h>
#include<stdlib.h>

void createGraph(int *adj[], int n)
{
    for(int i=0;i<n;i++)
    {
        adj[i] = calloc(n, sizeof(int));
    }
}

void dfs1(int *adj[], int n, int curr, int par, int depth[], int level)
{
    depth[curr] = level++;    
    for(int i=0;i<n;i++)
    {
        if(adj[curr][i] && i != par)
        {
            dfs1(adj, n, i, curr, depth, level);
        }
    }
}

int dfs2(int *adj[], int n, int curr, int par, int lowest[])
{
    int level = 0;
    for(int i=0;i<n;i++)
    {
        if(adj[curr][i] && i != par)
        {
            int temp = dfs2(adj, n, i, curr, lowest);
            level = (level > temp)?level:temp;
        }
    }
    lowest[curr] = level + 1;
    return level + 1;
}

int main()
{
    int n, x;
    scanf("%d %d", &n, &x);
    x--;

    int *adj[n];
    createGraph(adj, n);

    for(int i=0;i<n-1;i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a-1][b-1] = adj[b-1][a-1] = 1;
    }

    int dx[n], d0[n], lowest[n];
    dfs1(adj, n, 0, -1, d0, 0);
    dfs1(adj, n, x, -1, dx, 0);
    dfs2(adj, n, 0, -1, lowest);

    int ans = 0;
    for(int i=0;i<n;i++)
    {
        if(dx[i] < d0[i])
        {
            int temp = d0[i] + lowest[i];
            if(temp > ans)
            {
                ans = temp;
            }
        }
    }
    printf("%d\n", ans*2-2);
    return 0;
}