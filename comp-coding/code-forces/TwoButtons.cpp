// https://codeforces.com/contest/520/problem/B
#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin>>n>>m;

    int count = 0;
    while(m != n)
    {
    	if(m < n)
    	{
    		m++;
	    	count++;
    	}
    	else
    	{
    		if(m%2 == 0)
    		{
    			m=m/2;
    			count++;
    		}
    		else
    		{
    			m = (m+1)/2;
    			count+=2;
    		}
    	}
    }
    cout<<count<<endl;
    return 0;
}