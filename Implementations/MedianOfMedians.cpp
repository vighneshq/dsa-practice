#include<iostream>

using namespace std;

int sort(int arr[], int start, int end)
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
    return arr[(start+end)/2];
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
            medians[index++] = sort(arr, i, i + 4);
        }
        else
        {
            medians[index++] = sort(arr, i, n-1);
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
    else if(k <= n - high)
    {
        return pivot;
    }
    else
    {
        return kthOrderStatistic(higher, high, k - (n - high));
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