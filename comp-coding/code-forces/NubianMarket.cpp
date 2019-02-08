// https://codeforces.com/problemset/problem/812/C
// Improved version of assignment 4, question 1.
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

ll price(ll arr[], ll temp[], int n, int k)
{
	for(int i=0;i<n;i++)
	{
		temp[i] = arr[i] + (i+1)*k;
	}
	sort(temp, temp+n);
	ll cost = 0;
	for(int i=0;i<k;i++)
	{
		cost += temp[i];
	}
	return cost;
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    ll S;
    cin>>n>>S;

    ll arr[n];
    for(int i=0;i<n;i++)
    {
    	cin>>arr[i];
    }

    int l = 0, h = n, max = 0;
    ll temp[n];
    ll cost = 0;
    while(l <= h)
    {
    	int k = (l+h+1)/2;
    	ll sum = price(arr, temp, n, k);
    	// debug2(k, sum);
    	if(sum == S)
    	{
    		max = k;
    		cost = sum;
    		break;
    	}
    	else if(sum > S || sum < 0)
    	{
    		h = k - 1;
    	}
    	else
    	{
    		max = k;
    		cost = sum;
    		l = k + 1;
    	}
    }
    cout<<max<<" "<<cost<<endl;
    return 0;
}