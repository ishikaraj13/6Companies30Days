#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void dfs(int i,vector<vector<int>>& graph,vector<bool>& visit,string& ans)
    {
        visit[i]=1;
        for(auto x: graph[i])
        {
            if(!visit[x])
                dfs(x,graph,visit,ans);
        }
        char c=i+'a';
        ans=c+ans;
        return;
    }
    string findOrder(string dict[], int n, int k) 
    {
        vector<vector<int>> graph(k);
        
        for(int i=0;i<n-1;i++)
        {
            string w1=dict[i];
            string w2=dict[i+1];
            for(int j=0;j<min(w1.length(),w2.length());j++)
            {
                if(w1[j]!=w2[j])
                {
                    graph[w1[j]-'a'].push_back(w2[j]-'a');
                    break;
                }
            }
        }
        vector<bool> visit(26,false);
        string ans="";
        for(int i=0;i<k;i++)
        {
            if(!visit[i])
                dfs(i,graph,visit,ans);
        }
        
        return ans;
        
    }
};

string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

int main() 
{
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}