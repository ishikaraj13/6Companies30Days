#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
  
	int minDifference(int arr[], int n)  
	{ 
	    int sum=0;
        for(int i=0;i<n;i++) 
            sum+=arr[i];
        
        vector<vector<int>> dp(n,vector<int> (sum+1,-1));
        
        return solve(arr,n-1,0,0,dp);
    }
    
    int solve(int a[], int n, int S1, int S2,vector<vector<int>>& dp)
    {
        if(n<0) 
            return abs(S1-S2);
    
        if(dp[n][S1]!=-1)
            return dp[n][S1];
            
        int inc=solve(a,n-1,S1+a[n],S2,dp);
        int exc=solve(a,n-1,S1,S2+a[n],dp);
        
        dp[n][S1]=min(inc,exc);
        return dp[n][S1];
        
    }
};

int main() 
{ 
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";   
    }
    return 0;
}  