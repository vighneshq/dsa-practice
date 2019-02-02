// https://codeforces.com/contest/1037/problem/D
#include <bits/stdc++.h>

using namespace std;

vector<int>* g;
int* seq;
int *pos;

bool comparePos(int a, int b)
{
	return pos[a] <= pos[b];
}

// Sort adjacency list based on the position in the given sequence
void sortNeighbours(int n)
{
	for(int i=1;i<=n;i++)
	{
		sort(g[i].begin(), g[i].end(), comparePos);
	}
}

bool bfs(int source, int n)
{
	bool* visited = new bool[n+1];
	memset(visited, 0, (n+1)*sizeof(bool));

	queue<int> q;
	q.push(source);
	visited[source] = true;
	int index = 1;
	while(!q.empty())
	{
		int curr = q.front();
		q.pop();
		if(seq[index++] != curr)
		{
			return false;
		}
		for(int i=0;i<g[curr].size();i++)
		{
			int j = g[curr][i];
			if(!visited[j])
			{
				q.push(j);
				visited[j] = 1;
			}
		}
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    g = new vector<int>[n+1];
    for(int i=1;i<=n-1;i++)
    {
    	int x, y;
    	cin>>x>>y;
    	g[x].push_back(y);
    	g[y].push_back(x);
    }

    seq = new int[n+1];
    pos = new int[n+1];
    for(int i=1;i<=n;i++)
    {
    	cin>>seq[i];
    	pos[seq[i]] = i;
    }

    sortNeighbours(n);
  	bool valid = bfs(1,n);
   
    if(valid)
    {
    	cout<<"Yes"<<endl;
    }
    else
   	{
   		cout<<"No"<<endl;
   	}
    return 0;
}