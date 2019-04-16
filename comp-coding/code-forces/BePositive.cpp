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
    
    int n, t, p = 0, z = 0, k = 0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>t;
        p += (t>0);
        z += (t==0);
        k += (t<0);
    }
    int x = (n+1)/2;

    if(p>=x)
    {
        cout<<1<<endl;
    }
    else
    {
        if(k >= x)
        {
            cout<< -1<<endl;
        }
        else
        {
            cout<<0<<endl;
        }

    }
    return 0;
}