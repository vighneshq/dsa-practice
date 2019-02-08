#include <bits/stdc++.h>

using namespace std;

#define debug1(a) cerr<<#a<<": "<<a<<endl;
#define debug2(a,b) cerr<<#a<<": "<<a<<", "<<#b<<": "<<b<<endl;
#define debug3(a,b,c) cerr<<#a<<": "<<a<<", "<<#b<<": "<<b<<", "<<#c<<": "<<c<<endl;
#define debug4(a,b,c,d) cerr<<#a<<": "<<a<<", "<<#b<<": "<<b<<", "<<#c<<": "<<c<<", "<<#d<<": "<<d<<endl;
#define debug5(a,b,c,d,e) cerr<<#a<<": "<<a<<", "<<#b<<": "<<b<<", "<<#c<<": "<<c<<", "<<#d<<": "<<d<<", "<<#e<<": "<<e<<endl;

typedef long long int ll;
typedef vector<int> vi;
typedef vector<long long> vll;

vi* g;

void bfsSeq(int src, int N, int seq[], int parent[], bool vis[])
{
	memset(vis, 0, (N+1)*sizeof(bool));	
	queue<int>q;
	q.push(src);
	vis[src] = true;
	parent[src] = -1;
	int index = 1;
	while(!q.empty())
	{
		int curr = q.front();
		seq[index++] = curr;
		q.pop();
		for(auto it : g[curr])
		{
			if(!vis[it])
			{
				q.push(it);
				vis[it] = true;
				parent[it] = curr;
			}
		}
	}
}

void dfsflip(int curr, int init[], int par, bool vis[], int flip)
{
	vis[curr] = 1;
	if(flip)
	{
		init[curr] = 1-init[curr];
	}
	for(auto it : g[curr])
	{
		if(!vis[it] && it != par)
		{
			dfsflip(it, init, curr, vis, 1-flip);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin>>N;
    g = new vi[N+1];
    for(int i=1;i<=N-1;i++)
    {
    	int u, v;
    	cin>>u>>v;
    	g[u].push_back(v);
    	g[v].push_back(u);
    }

    int init[N+1];
    int goal[N+1];
    for(int i=1;i<=N;i++)
    {
    	cin>>init[i];
    }
    for(int i=1;i<=N;i++)
    {
    	cin>>goal[i];
    }

    int seq[N+1];
    int parent[N+1];
	bool vis[N+1];

    bfsSeq(1, N, seq, parent, vis);
    int order[N+1];

    int count = 0;
    for(int i=1;i<=N;i++)
    {
    	int node = seq[i];
    	if(init[node] != goal[node])
    	{
    		order[count++] = node;
    		memset(vis, 0, (N+1)*sizeof(bool));
    		dfsflip(node, init, parent[node], vis , 1);
    	}
    }

    cout<<count<<endl;
    for(int i=0;i<count;i++)
    {
    	cout<<order[i]<<endl;
    }
    return 0;
}