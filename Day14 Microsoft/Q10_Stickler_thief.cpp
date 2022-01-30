#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Solution
{
    public:
    int FindMaxSum(int a[], int n)
    {
        if(n==1)
            return a[0];
            
        if(n==2)
            return max(a[0],a[1]);
            
        vector<int> dp(n+1,0);
        dp[0]=0;
        dp[1]=a[0];
        for(int i=2;i<=n;i++)
        {
            dp[i]=max(dp[i-1],dp[i-2]+a[i-1]);
        }
        
        return dp[n];
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
		int a[n];
		
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}