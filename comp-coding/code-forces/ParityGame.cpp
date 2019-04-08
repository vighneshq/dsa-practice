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

    int even[n], odd[n], e = 0, o = 0, sum = 0, temp;
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        sum += temp;
        if(temp%2)
        {
            odd[o++] = temp;
        }
        else
        {
            even[e++] = temp;
        }
    }
    sort(even,even+e);
    sort(odd, odd+o);
    if(e == o)
    {
        cout<<"0\n";
    }
    else if(e > o)
    {
        while(e > 0 && o > 0)
        {
            sum -= even[--e];
            sum -= odd[--o];
        }
        if(e > 0)
        {
            sum -= even[--e];            
        }
        cout<<sum<<endl;
    }
    else
    {
        while(e > 0 && o > 0)
        {
            sum -= odd[--o];
            sum -= even[--e];
        }
        if(o > 0)
        {
            sum -= odd[--o];            
        }
        cout<<sum<<endl;
    }
    return 0;
}