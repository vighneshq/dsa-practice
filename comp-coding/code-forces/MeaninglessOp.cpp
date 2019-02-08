// https://codeforces.com/contest/1110/problem/C
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

int isPower2(int n)
{
	bool ans = true;
	while(n > 1)
	{
		if(n%2 == 1)
		{
			return false;
		}
		n = n/2;
	}
	return true;
}

int log2(int n)
{
	int ans = 0;
	while(n > 1)
	{
		ans++;
		n = n/2;
	}
	return ans;
}

int pow(int p, int base)
{
	int ans = 1;
	for(int i=1;i<=p;i++)
	{
		ans = ans*base;
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
 	int q;
 	cin>>q;
 	while(q--)
 	{
 		int a;
 		cin>>a;
 		if(isPower2(a+1))
 		{
 			int max = 1;
 			for(int i=2;i*i<=a;i++)
 			{
 				if(a%i == 0)
 				{
 					max = (max>a/i)?max:a/i;
 				}
 			}
 			cout<<max<<endl;
 		}
 		else
 		{
 			cout<<pow(log2(a)+1,2)-1<<endl;
 		}
 	}
	return 0;
}