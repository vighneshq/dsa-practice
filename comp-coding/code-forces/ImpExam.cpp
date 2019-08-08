// https://codeforces.com/contest/1201/problem/A
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

typedef struct
{
    int a, b, c, d, e;
} Question;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin>>n>>m;
    

    Question q[m];
    for(int i=0;i<m;i++)
    {
        q[i] = {0, 0, 0, 0, 0};
    }

    string answers;
    for(int i=0;i<n;i++)
    {
        cin>>answers;
        for(int j=0;j<m;j++)
        {
            switch(answers[j])
            {
                case 'A':
                    q[j].a += 1;
                    break;
                case 'B':
                    q[j].b += 1;
                    break;
                case 'C':
                    q[j].c += 1;
                    break;
                case 'D':
                    q[j].d += 1;
                    break;
                case 'E':
                    q[j].e += 1;
            }
        }
    }

    int points;
    long total = 0;
    for(int i=0;i<m;i++)
    {
        cin>>points;
        total += points * max(q[i].a, max(q[i].b, max(q[i].c, max(q[i].d, q[i].e))));
    }
    cout<<total<<endl;
    return 0;
}