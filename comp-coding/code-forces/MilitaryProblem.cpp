// https://codeforces.com/contest/1006/problem/E
#include <bits/stdc++.h>

using namespace std;

vector<int>* g;
bool* visited;
int* seq;
int *under;
int *pos;

// Calculate the number of nodes in the subtree of curr
// Also generate the dfs sequence from the root (vertex 1)
void dfs(int curr, int* index)
{
	if(visited[curr])
	{
		return;
	}
	visited[curr] = true;
	seq[*index] = curr;
	pos[curr] = (*index)++;
	under[curr] = 1;
	for(int i=0;i<g[curr].size();i++)
	{
		int j = g[curr][i];
		if(!visited[j])
		{
			dfs(j, index);
			under[curr] += under[j];
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin>>n>>q;
    g = new vector<int>[n+1];
    visited = new bool[n+1];
    memset(visited, 0, (n+1)*sizeof(bool));
    seq = new int[n+1];
    under = new int[n+1];
    pos = new int[n+1];

    for(int i=2;i<=n;i++)
    {
    	int p;
    	cin>>p;
    	g[p].push_back(i);
    }
    int index = 1;
    dfs(1, &index);

    while(q--)
    {
    	int u, k;
    	cin>>u>>k;
    	if(k > under[u])
    	{
    		cout<<"-1"<<endl;
    	}
    	else
    	{
    		cout<<seq[pos[u]+k-1]<<endl;
    	}
    }
    return 0;
}