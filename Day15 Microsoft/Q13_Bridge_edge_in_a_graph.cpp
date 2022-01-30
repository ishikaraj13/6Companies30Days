#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
    int isBridge(int v, vector<int> adj[], int c, int d) 
    {
        adj[c].erase(find(adj[c].begin(),adj[c].end(),d));
        adj[d].erase(find(adj[d].begin(),adj[d].end(),c));
        
        vector<bool> visit(v,false);
        queue<int> q;
        q.push(c);
        visit[c]=1;
        while(!q.empty())
        {
            int cur=q.front();
            q.pop();
            for(int i=0;i<adj[cur].size();i++)
            {
                if(visit[adj[cur][i]]==0)
                {
                    visit[adj[cur][i]]=1;
                    q.push(adj[cur][i]);
                }
            }
        }
        if(visit[d])
            return 0;
        return 1;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}


