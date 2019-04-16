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

void swap(int* a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int w, h, u1, d1, u2, d2;
    cin>>w>>h;
    cin>>u1>>d1;
    cin>>u2>>d2;
    if(d1 < d2)
    {
        swap(&d1, &d2);
        swap(&u1, &u2);
    }
    w +=  h*(h+1)/2 - d1*(d1-1)/2;
    w -=  u1;
    if(w<=0)
    {
        w = 0;
    }
    h = d1 - 1;
    w += h*(h+1)/2 - d2*(d2-1)/2;
    w -= u2;
    if(w<=0)
    {
        w = 0;
    }
    h = d2 - 1;
    w += h*(h+1)/2;
    cout<<w<<endl;
    return 0;
}