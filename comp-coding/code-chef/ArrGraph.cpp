// https://www.codechef.com/problems/ARRGRAPH
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

int gcd(int a, int b)
{
	if(b == 0)
	{
		return a;
	}
	else
	{
		return gcd(b, a%b);
	}
}

void dfs(int curr, int N, bool vis[], int A[])
{
	vis[curr] = true;
	for(int i=1;i<=N;i++)
	{
		if(!vis[i] && gcd(A[curr], A[i]) == 1)
		{
			dfs(i, N, vis, A);
		}
	}
}

void printArray(int arr[], int N)
{
	for(int i=1;i<=N;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin>>T;
    while(T--)
    {
    	int N;
    	cin>>N;
    	int A[N+1];
    	for(int i=1;i<=N;i++)
    	{
    		cin>>A[i];
    	}
    	bool *vis = new bool[N+1];
    	int count = 0;
    	for(int i=1;i<=N;i++)
    	{
    		if(!vis[i])
    		{
    			count++;
    			dfs(i, N, vis, A);
    		}
    	}
    }
    return 0;
}