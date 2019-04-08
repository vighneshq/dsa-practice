// http://codeforces.com/problemset/problem/546/C
//a
#include<iostream>
#include<queue>

using namespace std;

int main()
{
	int n, k1, k2, temp;
	cin>>n;
	queue<int> q1;
	queue<int> q2;
	cin>>k1;
	for(int i=0;i<k1;i++)
	{
		cin>>temp;
		q1.push(temp);
	}
	cin>>k2;	
	for(int i=0;i<k2;i++)
	{
		cin>>temp;
		q2.push(temp);
	}
	int count = 0;
	int x, y;
	while(true)
	{
		if(q1.empty())
		{
			cout<<count<<" "<<2<<endl;
			break;
		}
		else if(q2.empty())
		{
			cout<<count<<" "<<1<<endl;	
			break;
		}
		else
		{
			x = q1.front();
			y = q2.front();
			q1.pop();
			q2.pop();
			if(x>y)
			{
				q1.push(y);
				q1.push(x);

			}
			else
			{
				q2.push(x);
				q2.push(y);
			}
			count++;
		}
		if(count>10000)
		{
			cout<<-1<<endl;
			break;
		}
	}
	return 0;
}