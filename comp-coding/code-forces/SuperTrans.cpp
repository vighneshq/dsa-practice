// https://codeforces.com/contest/1111/problem/A
#include <bits/stdc++.h>

using namespace std;

bool isVowel(char c)
{
	return (c == 'a' || c == 'e' || c =='i' || c == 'o' || c == 'u');
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s, t;
    cin>>s;
    cin>>t;
    if(s.length() != t.length())
    {
    	cout<<"No"<<endl;
    }
    else
    {
    	int n = s.length();
    	for(int i=0;i<n;i++)
    	{
    		if(isVowel(s[i]) && !isVowel(t[i]))
    		{
    			cout<<"No"<<endl;
    			return 0;
    		}
    		else if(!isVowel(s[i]) && isVowel(t[i]))
    		{
    			cout<<"No"<<endl;
    			return 0;
    		}
    	}
    	cout<<"Yes"<<endl;
    }
    return 0;
}