#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
		string FirstNonRepeating(string s)
		{
		    int n=s.length();
		    string res="";
		    int freq[27]={0};
		    queue<char> q;
		    
		    for(int i=0;i<n;i++)
		    {
		        char c=s[i];
		        freq[c-'a']++;
		        if(freq[c-'a']==1)
		            q.push(c);
		        else
		        {
		            while(!q.empty() && freq[q.front()-'a']!=1)
		                q.pop();
		        }
		        if(!q.empty())
		            res+=q.front();
		        else 
		            res+='#';
		    }
		    
		    return res;
		}

};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  