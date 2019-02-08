// https://codeforces.com/contest/1097/problem/A
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
  
	string s;
	cin>>s;

	char val, suit;
	val = s[0];
	suit = s[1];

	for(int i=0;i<5;i++)
	{
		cin>>s;
		if(val == s[0] || suit == s[1])
		{
			cout<<"YES\n";
			return 0;
		}
	}    
	cout<<"NO\n";
    return 0;
}