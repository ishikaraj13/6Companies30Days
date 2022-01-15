#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    vector<int> calculateSpan(int a[], int n)
    {
        vector<int> res(n,0);
        stack<pair<int,int>> s;
        
        for(int i=0;i<n;i++)
        {
            int ans=0;
            if(s.empty())
                ans=1;
            else if(s.top().first>a[i])
                ans=1;
            else
            {
                while(!s.empty() && s.top().first<=a[i])
                    s.pop();
                if(s.empty())
                    s.push(make_pair(0,-1));
                ans=i-s.top().second;
            }
            res[i]=ans;
            s.push(make_pair(a[i],i));
        }
        return res;
    }
};


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}