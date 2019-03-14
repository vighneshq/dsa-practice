#include<iostream>

using namespace std;

int lsearch(int a[], int n, int x)
{
    for(int i=0;i<n;i++)
    {
        if(a[i] == x)
        {
            return i;
        }
    }
    return -1;
}

int lsearchSentinel(int a[], int n, int x)
{
    int temp = a[n-1];
    a[n-1] = x;
    int i = 0;
    while(a[i] != x)
    {
        i++;
    }
    if(i<n-1 || temp == x)
    {
        return i;
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

    cout<<lsearch(a,n,x)<<endl;
    return 0;
}