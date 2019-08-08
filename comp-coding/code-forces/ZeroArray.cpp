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

    ll arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    ll sum = 0;
    int max = arr[0];
    for(int i=0;i<n;i++)
    {
        sum += arr[i];
        max = max>arr[i]?max:arr[i];
    }
    if(sum%2 == 0 && max <= sum - max)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    return 0;
}