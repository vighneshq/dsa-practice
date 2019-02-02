// https://codeforces.com/problemset/problem/902/B
#include <bits/stdc++.h>

using namespace std;

class Tree
{
	private:
		int v;
		vector<int>* adj;
		bool* visited;
		int* assigned;
	public:
		Tree(int);
		void dfs(int, int);
		void addEdge(int, int);
		int color(int[]);
};

Tree::Tree(int n)
{
	v = n;
	adj = new vector<int>[n];
	visited = new bool[n];
	assigned = new int[n];
}

void Tree::addEdge(int x, int y)
{
	adj[x].push_back(y);
}

void Tree::dfs(int curr, int color)
{
	if(visited[curr])
	{
		return;
	}

	visited[curr] = true;
	assigned[curr] = color;
	for(int i=0;i<adj[curr].size();i++)
	{
		int j = adj[curr][i];
		if(!visited[j])
		{
			dfs(j, color);
		}
	}
}

int Tree::color(int colors[])
{
	bool vis[v];
	memset(vis, 0, v*sizeof(bool));
	memset(assigned, 0, v*sizeof(int));

	int count = 0;
	queue<int> q;
	q.push(0);
	vis[0] = true;
	while(!q.empty())
	{
		int curr = q.front();
		q.pop();
		if(assigned[curr] != colors[curr])
		{
			memset(visited, 0, v*sizeof(bool));
			dfs(curr, colors[curr]);
			count++;
		}
		for(int i=0;i<adj[curr].size();i++)
		{
			int j = adj[curr][i];
			if(!vis[j])
			{
				q.push(j);
				vis[j] = true;
			}
		}
	}
	return count;
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

  	int n;
  	cin>>n;
  	Tree T(n);
  	for(int i=2;i<=n;i++)
  	{
  		int p;
  		cin>>p;
  		T.addEdge(p-1, i-1);
  	}

  	int colors[n];
  	for(int i=0;i<n;i++)
  	{
  		cin>>colors[i];
  	}

  	cout<<T.color(colors)<<endl;
    return 0;
}