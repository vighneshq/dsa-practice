// More efficient C++ implementation of Assignment 3 Question 4.
// Also a question on CodeForces 
// https://codeforces.com/problemset/problem/979/C
#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

class Tree
{
	private:
		int v;
		vector<int>* adj;
		bool* visited;
		int* subtree;
	public:
		Tree(int);
		void addEdge(int, int);
		int dfsHelper(int, int);
		void dfs(int, int);
};

Tree::Tree(int n)
{
	v = n;
	adj = new vector<int>[n];
	visited = new bool[n];
	subtree = new int[n];
}

void Tree::addEdge(int x, int y)
{
	adj[x].push_back(y);
	adj[y].push_back(x);
}

int Tree::dfsHelper(int curr, int other)
{
	memset(visited, 0, v*sizeof(bool));
	memset(subtree, -1, v*sizeof(int));
	
	dfs(curr, other);

	int count = 0;
	for(int i=0;i<v;i++)
	{
		if(subtree[i] == other)
		{
			count++;
		}
	}
	return count;
}

void Tree::dfs(int curr, int other)
{
	if(visited[curr])
	{
		return;
	}
	visited[curr] = true;
	subtree[other] = other;

	for(int i=0;i<adj[curr].size();i++)
	{
		int j = adj[curr][i];
		if(!visited[j])
		{
			subtree[j] = subtree[curr];
			dfs(j, other);
		}
	}
}

int main()
{
	int n, x, y;
	cin>>n>>x>>y;
	x--;
	y--;

	Tree T(n);
	for(int i=0;i<n-1;i++)
	{
		int a, b;
		cin>>a>>b;
		T.addEdge(a-1, b-1);
	}

	long long int xTree = T.dfsHelper(y, x);
	long long int yTree = T.dfsHelper(x, y);
	long long int N = n;
	cout<<N*(N-1) - xTree*yTree<<endl;
	return 0;
}