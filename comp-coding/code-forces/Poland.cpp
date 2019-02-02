// https://codeforces.com/problemset/problem/755/C
#include <bits/stdc++.h>

using namespace std;

set<int>* g;
bool* vis;

void dfs(int curr)
{
	if(vis[curr])
	{
		return;
	}
	vis[curr] = true;
	for(auto it : g[curr])
	{
		if(!vis[it])
		{
			dfs(it);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    g = new set<int>[n+1];
    for(int i=1;i<=n;i++)
    {
    	int p;
    	cin>>p;
    	g[i].insert(p);
    	g[p].insert(i);
    }
    int count = 0;
    vis = new bool[n+1];
    memset(vis, 0, (n+1)*sizeof(bool));
    for(int i=1;i<=n;i++)
    {
    	if(!vis[i])
    	{
    		count++;
    		dfs(i);
    	}
    }
    cout<<count<<endl;
    return 0;
}