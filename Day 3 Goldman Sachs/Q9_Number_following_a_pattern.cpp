#include<bits/stdc++.h> 
using namespace std; 

class Solution{   
public:
    string printMinNumberForPattern(string s)
    {
        int n=s.length(),temp=1;
        stack<int> st;
        string res="";
        for(int i=0;i<n;i++)
        {
            st.push(temp);
                temp++;
            if(s[i]=='I')
            {
                while(!st.empty())
                {
                    res+=('0'+st.top());
                    st.pop();
                }
            }
        }
        st.push(temp);
        while(!st.empty())
        {
            res+=st.top()+'0';
            st.pop();
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
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 
