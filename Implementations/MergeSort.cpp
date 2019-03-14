#include<iostream>

using namespace std;

void merge(int a[], int l, int m, int h)
{
    int p = m - l + 1;
    int q = h - m;

    int L[p], R[q];
    for(int i=0;i<p;i++)
    {
        L[i] = a[l+i];
    }
    for(int j=0;j<q;j++)
    {
        R[j] = a[m+j+1];
    }

    int i = 0, j = 0, k = l;
    while(i<p && j<q)
    {
        if(L[i] > R[j])
        {
            a[k++] = R[j++];
        }
        else
        {
            a[k++] = L[i++];
        }
    }
    while(i<p)
    {
        a[k++] = L[i++];
    }
    while(j<q)
    {
        a[k++] = R[j++];
    }
}

void mergeSort(int a[], int l, int h)
{
    if(l<h)
    {;
        int m = (l+h)/2;
        mergeSort(a,l,m);
        mergeSort(a,m+1,h);
        merge(a,l,m,h);
    }
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

    mergeSort(a,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}