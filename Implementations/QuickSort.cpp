#include<iostream>

using namespace std;

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int arr[], int p, int r)
{
    int pivot = arr[r];
    int i = p - 1;
    for(int j=p;j<r;j++)
    {
        if(arr[j] <= pivot)
        {
            i++;
            swap(arr, i, j);
        }
    }
    i++;
    swap(arr, i, r);
    return i;
}

int hoare_partition(int arr[], int p, int r)
{
    int pivot = arr[p];
    int i = p;
    int j = r;
    while(1)
    {
        while(arr[j] > pivot)
        {
            j--;
        }
        while(arr[i] < pivot)
        {
            i++;
        }
        if(i < j)
        {
            swap(arr, i, j);
        }
        else
        {
            return j;
        }
    }
}

void quicksort(int arr[], int p, int r)
{
    if(p < r)
    {
        int q = partition(arr, p, r);
        quicksort(arr, p, q - 1);
        quicksort(arr, q+1, r);
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

    quicksort(a,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}