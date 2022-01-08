#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int dp[501][2][201];
    int sol(int a[],int i,bool own,int k,int n)
    {
        if(i>=n || k<=0)
            return 0;
        if(dp[i][own][k]!=-1)
            return dp[i][own][k];
        
        if(own)
            dp[i][own][k] = max( sol(a,i+1,own,k,n) , a[i]+sol(a,i+1,0,k-1,n) );
        else
            dp[i][own][k] = max( sol(a,i+1,own,k,n) , -a[i]+sol(a,i+1,1,k,n) );
        
        return dp[i][own][k];
    }
    
    int maxProfit(int k, int n, int prices[]) 
    {
        memset(dp,-1,sizeof dp);
        if(n==0)
            return 0;
        return sol(prices,0,0,k,n);
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
} 