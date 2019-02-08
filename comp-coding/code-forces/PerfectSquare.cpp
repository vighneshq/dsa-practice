// https://codeforces.com/contest/914/problem/A
#include <bits/stdc++.h>

using namespace std;

bool isSquare(int k)
{
	for(int i=0;i*i<=k;i++)
	{
		if(i*i == k)
		{
			return true;
		}
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
    	cin>>a[i];
    }
    sort(a,a+n);
    for(int i=n-1;i>=0;i--)
    {
    	if(!isSquare(a[i]))
    	{
    		cout<<a[i]<<endl;
    		return 0;
    	}
    }
    return 0;
}