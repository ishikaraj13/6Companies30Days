#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    long long countWays(int m)
    {
        // your code here
        if(m==1)
            return 1;
        if(m==2)
            return 2;
        vector<int> dp(m+1,0);
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        
        for(int i=3;i<=m;i++)
            dp[i]=1+dp[i-2];
        
        return dp[m];
    }
};

int main()
{
    //taking count of testcases
    int t;
    cin >> t;
    
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}  