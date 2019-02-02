// https://codeforces.com/problemset/problem/690/C2
#include <bits/stdc++.h>

using namespace std;

vector<int>* g;
int* dist;

void bfs(int source, int n)
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
		for(auto it : g[curr])
		{
			if(!visited[it])
			{
				q.push(it);
				visited[it] = true;
				dist[it] = dist[curr] + 1;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;

    g = new vector<int>[n+1];
    for(int i=1;i<=m;i++)
    {
    	int a, b;
    	cin>>a>>b;
    	g[a].push_back(b);
    	g[b].push_back(a);
    }

    dist = new int[n+1];
    bfs(1, n);

    int a = 1;
    for(int i=1;i<=n;i++)
    {
    	if(dist[i] > dist[a])
    	{
    		a = i;
    	}
    }
   	
   	bfs(a, n);
   	int max = 0;
   	for(int i=1;i<=n;i++)
   	{
   		if(dist[i] > max)
   		{
   			max = dist[i];
   		}
   	}
   	cout<<max<<endl;
    return 0;
}