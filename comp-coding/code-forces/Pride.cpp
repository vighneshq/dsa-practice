// https://codeforces.com/problemset/problem/892/C
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

ll gcd(ll a, ll b)
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

ll min(ll a, ll b)
{
	return a<b?a:b;
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;

    ll arr[n];
    int count = 0;
    for(int i=0;i<n;i++)
    {
    	cin>>arr[i];
    	if(arr[i] == 1)
    	{
    		count++;
    	}
    }

    if(count > 0)
    {
    	cout<<n - count<<endl;
    	return 0;
    }
    int ans = -1;
    for(int i=0;i<n;i++)
    {
    	ll d = 0;
    	int j;
    	for(j=i;j<n;j++)
    	{
    		d = gcd(d, arr[j]);
    		if(d == 1)
    		{
    			break;
    		}
    	}
    	if(d == 1)
    	{
    		if(ans == -1)
    		{
    			ans = j - i;
    		}
    		else
    		{
    			ans = min(ans, j - i);
    		}
    	}
    }
    if(ans == -1)
    {
    	cout<<-1<<endl;
    }
    else
    {
    	cout<<ans+n-1<<endl;
    }
    return 0;
}