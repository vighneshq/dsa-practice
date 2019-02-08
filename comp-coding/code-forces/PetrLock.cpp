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
    
 	int n;
 	cin>>n;

 	int arr[n];
 	for(int i=0;i<n;i++)
 	{
 		cin>>arr[i];
 	}

 	int lim = (1<<n) - 1;
 	for(int i=0;i<=lim;i++)
 	{
 		int sum = 0;
 		for(int j=0;j<n;j++)
 		{
 			int choice = (i & (1<<j));
 			if(choice)
 			{
 				sum = sum + arr[j];
	 			}
 			else
 			{
 				sum = sum - arr[j];
 			}
 		}
 		if(sum%360 == 0)
 		{
 			cout<<"YES\n";
 			return 0;
 		}
 	}
 	cout<<"NO\n";
    return 0;
}