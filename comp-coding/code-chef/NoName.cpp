// https://www.codechef.com/COBE2019/problems/BLONDIE
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
   
    int T;
    cin>>T;
    while(T--)
    {
    	int N;
    	cin>>N;
    	ll sum = 0;
    	for(int i=0;i<N;i++)
    	{	
    		ll count;
    		cin>>count;
    		if(count == -1)
    		{
    			count = sum/i;
    		}
    		cout<<count<<" ";
    		sum += count;
    	}
    	cout<<endl;
    }
    return 0;
}