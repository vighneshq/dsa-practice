#include<iostream>

using namespace std;

int bsearch(int a[], int n, int x)
{
    int l = 0, h = n - 1;
    while(l<h)
    {
        int m = (l+h)/2;
        if(a[m] == x)
        {
            return m;
        }
        else if(a[m] < x)
        {
            l = m + 1;
        }
        else
        {
            h = m - 1;
        }
    }
    return -1;
}

int main()
{
    int n;
    cin>>n;

    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    int x;
    cin>>x;

    cout<<bsearch(a,n,x)<<endl;
    return 0;
}