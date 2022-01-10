#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int isValid(vector<vector<int>> mat)
    {
        vector<set<int>> col(9),row(9),box(9);
        
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                int var=mat[i][j];
                if(var==0)
                    continue;
                
                int box_no= (i/3)+(j/3)*3;
                if( col[i].count(var) || row[j].count(var) || box[box_no].count(var))
                    return 0;
                
                col[i].insert(var);
                row[j].insert(var);
                box[box_no].insert(var);
            }
        }
        return 1;
    }
};


int main(){
    int t;
    cin>>t;
    while(t--){
        vector<vector<int>> mat(9, vector<int>(9, 0));
        for(int i = 0;i < 81;i++)
            cin>>mat[i/9][i%9];
        
        Solution ob;
        cout<<ob.isValid(mat)<<"\n";
    }
    return 0;
} 