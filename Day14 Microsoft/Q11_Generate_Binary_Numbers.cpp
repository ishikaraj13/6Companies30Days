#include<bits/stdc++.h>
using namespace std;

vector<string> generate(int n)
{
	vector<string> res;
	
	for(int i=1;i<=n;i++)
	{
	    int temp=i;
	    string s="";
	    while(temp)
	    {
	        s+='0'+(temp%2);
	        temp=temp/2;
	    }
	    reverse(s.begin(),s.end());
	    res.push_back(s);
	}
	
	return res;
}


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<string> ans = generate(n);
		for(auto it:ans) cout<<it<<" ";
		cout<<endl;
	}
	return 0;
} 