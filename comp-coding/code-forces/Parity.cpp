// https://codeforces.com/contest/1110/problem/A
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

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int b, k;
    cin>>b>>k;

    ll sum = 0;
    int digit;
    for(int i=1;i<=k;i++)
    {
    	cin>>digit;
    	sum += digit;
    }

    if(b%2 == 0)
    {
    	if(digit%2 == 0)
    	{
    		cout<<"even\n";
    	}
    	else
    	{
    		cout<<"odd\n";
    	}
    }
    else
    {
    	if(sum%2 == 0)
    	{
    		cout<<"even\n";
    	}
    	else
    	{
    		cout<<"odd\n";
    	}
    }
    return 0;
}