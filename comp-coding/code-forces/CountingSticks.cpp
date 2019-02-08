// https://codeforces.com/contest/394/problem/A
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
    
    string expr;
    cin>>expr;
    
    int n = expr.length();
    int a, b, c, p, e;
    for(int i=0;i<n;i++)
    {
    	if(expr[i] == '+')
    	{
    		p = i+1;
    	}
    	else if(expr[i] == '=')
    	{
    		e = i+1;
    	}
    }
    a = p - 1;
    b = e - p - 1;
    c = n - e;

    if(a + b == c)
    {
    	cout<<expr<<endl;
    }
    else if(a + b + 1 == c - 1)
    {
    	cout<<"|";
    	for(int i=0;i<n-1;i++)
    	{
    		cout<<expr[i];
    	}
    	cout<<endl;
    }
    else if(a + b - 1 == c + 1)
    {
    	if(a>=2)
    	{
    		for(int i=1;i<n;i++)
    		{
    			cout<<expr[i];
    		}
    		cout<<"|"<<endl;
    	}
    	else if(b>=2)
    	{
    		for(int i=0;i<e-2;i++)
    		{
    			cout<<expr[i];
    		}
    		for(int i=e-1;i<n;i++)
    		{
    			cout<<expr[i];
    		}
    		cout<<"|"<<endl;
    	}
    }
	else 
	{
		cout<<"Impossible"<<endl;
	}
    return 0;
}