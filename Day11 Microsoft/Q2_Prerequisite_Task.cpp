#include<bits/stdc++.h>
using namespace std;

class Solution 
{
public:

    bool detectcycle(vector<vector<int>>& adj,vector<int>& visited,int cur)
    {
        if(visited[cur]==2)
            return true;
        visited[cur]=2;
        for(int i=0;i<adj[cur].size();i++)
        {
            if(visited[adj[cur][i]]!=1)
            {
                if(detectcycle(adj,visited,adj[cur][i]))
                    return true;
            }
        }
        visited[cur]=1;
        return false;
    }
	bool isPossible(int n, vector<pair<int,int>>& a) 
	{
	    vector<vector<int>> adj(n);
	    
	    for(int i=0;i<a.size();i++)
	    {
	        adj[a[i].first].push_back(a[i].second);
	    }
	    
	    vector<int> visited(n,0);
	    
	    for(int i=0;i<n;i++)
	    {
	        if(visited[i]==0)
	        {
	            if(detectcycle(adj,visited,i))
	                return false;
	        }
	    }
	    return true;
	}
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  