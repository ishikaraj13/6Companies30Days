#include<bits/stdc++.h>
using namespace std;
void rotate (vector<vector<int> >& matrix);

void rotate(vector<vector<int>>& a)
{
    int n=a.size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            swap(a[i][j],a[n-j-1][n-i-1]);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n/2;j++)
        {
            swap(a[i][j],a[i][n-j-1]);
        }
    }
}

int main()
{
    int t;
    cin>>t; 
    while(t--)
    {
        int n;
        cin>>n; 
        vector<vector<int> > matrix(n);
        for(int i=0; i<n; i++)
        {
            matrix[i].resize(n);
            for(int j=0; j<n; j++)
                cin>>matrix[i][j]; 
        }
        rotate(matrix);
        for (int i = 0; i < n; ++i)
        {
            for(int j=0; j<n; j++)
                cout<<matrix[i][j]<<" ";
            cout<<"\n";
        }
    }
    return 0;
}