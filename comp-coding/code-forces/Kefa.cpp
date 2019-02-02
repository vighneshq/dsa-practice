// https://codeforces.com/problemset/problem/580/C
#include <bits/stdc++.h>

using namespace std;

vector<int>* g;
bool* cat;
void dfs(int curr, int par, int seen, int *count, int m)
{
	seen = cat[curr]*(seen+1);
	if(seen > m)
	{
		return;
	}
	if(g[curr].size() == 0 || (g[curr].size() == 1 && curr != 1))
	{
		(*count)++;
		return;
	}
	
	for(auto it : g[curr])
	{
		if(it != par)
		{
			dfs(it, curr, seen, count, m);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   	
   	int n, m;
   	cin>>n>>m;

   	cat = new bool[n+1];
   	for(int i=1;i<=n;i++)
   	{
   		cin>>cat[i];
   	}

   	g = new vector<int>[n+1];
   	for(int i=1;i<=n-1;i++)
   	{
   		int u, v;
   		cin>>u>>v;
   		g[u].push_back(v);
   		g[v].push_back(u);
   	}
   	int count = 0;
   	dfs(1, -1, 0, &count, m);
   	cout<<count<<endl;
    return 0;
}