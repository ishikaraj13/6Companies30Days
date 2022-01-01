#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& a) 
    {
        //code here
        int n=a.size();
        vector<string> orignal;
        for(string& s:a)
        {
            orignal.push_back(s);
            sort(s.begin(),s.end());
        }
       
        map<string,vector<int>> m;
        
        for(int i=0;i<n;i++)
        {
            string s=a[i];
            if(m.find(s)==m.end())
            {
                m[s]={i};
            }
            else
            {
                m[s].push_back(i);
            }
        }
        vector<vector<string>> res;
        for(auto it:m)
        {
            vector<int> temp_index=it.second;
            vector<string> temp_str;
            for(int i:temp_index)
                temp_str.push_back(orignal[i]);
            res.push_back(temp_str);
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
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        Solution ob;
        vector<vector<string> > result = ob.Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}