#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int temp;
    int di[8]={-1,-1,0,1,1,1,0,-1};
    int dj[8]={0,1,1,1,0,-1,-1,-1};
    void sol(vector<vector<int>>& a,int i,int j)
    {
        if(i<0 || j<0 || i>=a.size() || j>=a[0].size() || a[i][j]!=1)
            return;
        a[i][j]=2;
        temp++;
        for(int k=0;k<8;k++)
        {
            sol(a,i+di[k],j+dj[k]);
        }
        return;
    }
    int findMaxArea(vector<vector<int>>& grid) 
    {
        // Code here
        int res=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                    temp=0;
                    sol(grid,i,j);
                    res=max(res,temp);
                }
            }
        }
        return res;
    }
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
} 