#include<bits/stdc++.h>
using namespace std;

    int orangesRotting(vector<vector<int>>& a) 
    {
        int n=a.size(),m=a[0].size();
        queue<pair<int,int>> q;
        int fresh=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j]==2)
                    q.push({i,j});
                if(a[i][j]==1)
                    fresh++;
            }
        }
        int time=0;
        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                if(i-1>=0 && a[i-1][j]==1)
                {
                    a[i-1][j]=2;
                    fresh--;
                    q.push({i-1,j});
                }
                if(i+1<n && a[i+1][j]==1)
                {
                    a[i+1][j]=2;
                    fresh--;
                    q.push({i+1,j});
                }
                if(j-1>=0 && a[i][j-1]==1)
                {
                    a[i][j-1]=2;
                    fresh--;
                    q.push({i,j-1});
                }
                if(j+1<m && a[i][j+1]==1)
                {
                    a[i][j+1]=2;
                    fresh--;
                    q.push({i,j+1});
                } 
            }
            time++;
        }
        if(fresh>0)
            return -1;
        if(time==0)
            return time;
        return time-1;
    }

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> v(n,vector<int>(m,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>v[i][j];
        }
    }
    cout<<orangesRotting(v); 
    return 0;
}
