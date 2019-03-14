#include<iostream>

using namespace std;

void sort(int arr[], int start, int end)
{
    for(int i=start+1;i<=end;i++)
    {
        int key = arr[i];
        int j = i - 1;
        while(j>=start && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int kthOrderStatistic(int arr[], int n, int k)
{
    if(n <= 5)
    {
        sort(arr, 0, n-1);
        return arr[k-1];
    }
    int medians[n/5];
    int index = 0;
    for(int i=0;i<n;i+=5)
    {
        if(i+4 < n)
        {
            sort(arr, i, i + 4);
            medians[index++] = arr[i+2];
        }
        else
        {
            sort(arr, i, n-1);
            medians[index++] = arr[(i+n-1)/2];
        }
    }
    int pivot = kthOrderStatistic(medians, index, index/2);
    int lower[n], higher[n];
    int low = 0, high = 0;
    for(int i=0;i<n;i++)
    {
        if(arr[i] < pivot)
        {
            lower[low++] = arr[i];
        }
        else if(arr[i] > pivot)
        {
            higher[high++] = arr[i];
        }
    }
    if(k <= low)
    {
        return kthOrderStatistic(lower, low, k);
    }
    else if(k == low+1)
    {
        return pivot;
    }
    else
    {
        return kthOrderStatistic(higher, high, k - low - 1);
    }
    return 0;
}

int main()
{
    int n, k;
    cin>>n>>k;

    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<kthOrderStatistic(arr, n, k)<<endl;
    return 0;
}