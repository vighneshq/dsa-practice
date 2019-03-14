#include<iostream>

using namespace std;

void countingSortUtil(int a[], int n, int pos)
{
    int c[10], b[n];
    for(int i=0;i<=9;i++)
    {   
        c[i] = 0;
    }
    for(int i=0;i<n;i++)
    {
        int index = (a[i]/pos)%10;
        c[index]++;
    }
    for(int i=1;i<=9;i++)
    {
        c[i] += c[i-1];  
    }
    for(int i=n-1;i>=0;i--)
    {
        int index = (a[i]/pos)%10;
        b[c[index]-1] = a[i];
        c[index]--; 
    }
    for(int i=0;i<n;i++)
    {
        a[i] = b[i];
    }
}

void radixSort(int arr[], int n, int d)
{
    int pos = 1;
    while(d--)
    {
        countingSortUtil(arr, n, pos);
        pos *= 10;
    }
}

int main()
{
    int n, digits;
    cin>>n>>digits;

    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    radixSort(a, n, digits);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}