// https://codeforces.com/contest/914/problem/B
#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    int* count = new int[100005];
    for(int i=0;i<n;i++)
    {
    	int x;
    	cin>>x;
    	count[x]++;
    }

    for(int i=1;i<=1E5;i++)
    {
    	if(count[i]%2)
    	{
    		cout<<"Conan"<<endl;
    		return 0;
    	}
    }
    cout<<"Agasa"<<endl;
    return 0;
}