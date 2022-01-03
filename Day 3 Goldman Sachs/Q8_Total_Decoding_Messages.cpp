#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
	    long long int mod = 1e9 + 7;
	    long long sol(vector<long long>& dp,string& s,long long i)
	    {
	        if(i>=s.length())
	            return 1;
	            
	        if(s[i]=='0')
	            return 0;
	            
	        if(dp[i]!=-1)
	            return dp[i];
	           
	        long long res=sol(dp,s,i+1);
	        
	        if(i<s.length()-1 && (s[i]=='1' || (s[i]=='2' && s[i+1]<='6') ) )
	            res+=sol(dp,s,i+2);
	            
	        dp[i]=res%mod;
	        return dp[i];
	    }
		int CountWays(string str)
		{
		    // Code here
		    if(str.length()==0)
		        return 0;
		        
		    vector<long long> dp(str.length()+1,-1);
		    
		    return sol(dp,str,0);
		}

};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
} 