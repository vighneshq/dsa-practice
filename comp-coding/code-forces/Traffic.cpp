// https://codeforces.com/contest/954/problem/D
#include <bits/stdc++.h>

using namespace std;

vector<int>* g;

void bfs(int source, int n, int dist[])
{
	bool visited[n+1];
	memset(visited, 0, (n+1)*sizeof(bool));

	queue<int> q;
	q.push(source);
	visited[source] = true;
	dist[source] = 0;
	while(!q.empty())
	{
		int curr = q.front();
		q.pop();
		for(int i=0;i<g[curr].size();i++)
		{
			int j = g[curr][i];
			if(!visited[j])
			{
				q.push(j);
				visited[j] = true;
				dist[j] = dist[curr]+1;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, s, t;
    cin>>n>>m>>s>>t;

    g = new vector<int>[n+1];
    int adj[n+1][n+1];
    for(int i=1;i<=n;i++)
    {
    	for(int j=1;j<=n;j++)
    	{
    		adj[i][j] = 0;
    	}
    }

    for(int i=0;i<m;i++)
    {
    	int u, v;
    	cin>>u>>v;
    	g[u].push_back(v);
    	g[v].push_back(u);
    	adj[u][v] = adj[v][u] = 1;
    }

    int* ds = new int[n+1];
    int* dt = new int[n+1];
    bfs(s, n, ds);
    bfs(t, n, dt);

    int count = 0;
    int D = ds[t];
 	for(int i=1;i<=n;i++)
 	{
 		for(int j=i+1;j<=n;j++)
 		{
 			if(!adj[i][j])
 			{
 				if(ds[i] + dt[j] + 1 >= D && dt[i] + ds[j] + 1 >= D)
 				{	
 					count++;
 				}
 			}
 		}
 	}
 	cout<<count<<endl;
    return 0;
}