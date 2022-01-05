#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    string decodedString(string s)
    {
        int n=s.length();
        stack<string> st;
        for(int i=n-1;i>=0;i--)
        {
            char c=s[i];
            if(c=='[')
            {
                int num=0;
                string num_str="";
                while( i>=1 && s[i-1]>='0' && s[i-1]<='9')
                {
                    num_str+=s[i-1];
                    i--;
                }
                reverse(num_str.begin(),num_str.end());
                num=stoi(num_str);
                string temp="";
                while(st.top()!="]")
                {
                    temp+=st.top();
                    st.pop();
                }
                st.pop();
                while(num--)
                    st.push(temp);
            }
            else
            {
                string str(1,c);
                st.push(str);
            }
        }
        string res="";
        while(!st.empty())
        {
            res+=st.top();
            st.pop();
        }
        return res;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}  