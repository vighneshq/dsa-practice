// https://codeforces.com/problemset/problem/115/A
#include <bits/stdc++.h>

using namespace std;

void copy(int a[], int b[], int n)
{
	for(int i=1;i<=n;i++)
	{
		a[i] = b[i];
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int super[n+1];
    int indeg[n+1];
    memset(indeg, 0, (n+1)*sizeof(int));

    for(int i=1;i<=n;i++)
    {
    	cin>>super[i];
    	if(super[i] != -1)
    	{
    		indeg[super[i]]++;
    	}
    }

    int count = 0;
    int temp[n+1];
    while(true)
    {
    	bool stop = true;
    	copy(temp, indeg, n);
    	for(int i=1;i<=n;i++)
    	{
    		if(indeg[i] == 0)
    		{
    			temp[i]--;
    			if(super[i] != -1)
    			{
    				temp[super[i]]--;
    			}
    			stop = false;
    		}
    	}
    	if(stop)
    	{
    		break;
    	}
    	count++;
    	copy(indeg, temp, n);
    }
    cout<<count<<endl;
    return 0;
}