// https://codeforces.com/contest/393/problem/B
#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    int W[n][n];
    int WT[n][n];
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<n;j++)
    	{
    		cin>>W[i][j];
    		WT[j][i] = W[i][j];
    	}
    }

    double A[n][n];
    double B[n][n];
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<n;j++)
    	{
    		A[i][j] = (W[i][j] + WT[i][j])/2.0;
    		B[i][j] = (W[i][j] - WT[i][j])/2.0;
    	}
    }

    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<n;j++)
    	{
    		cout<<A[i][j]<<" ";
    	}
    	cout<<endl;
    }
     for(int i=0;i<n;i++)
    {
    	for(int j=0;j<n;j++)
    	{
    		cout<<B[i][j]<<" ";
    	}
    	cout<<endl;
    }
    return 0;
}