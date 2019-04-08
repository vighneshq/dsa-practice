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
    int c[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
    }
    int c1 = c[1], i = n;
    while(i >= 0 && c[i] == c1)
    {
        i--;
    }
    int ans1 = i - 1, j = 1;
    while(j <= n && c[j] == c1)
    {
        j++;
    }
    int ans2 = n - j;
    cout<<max(ans1, ans2)<<endl;
    return 0;
}