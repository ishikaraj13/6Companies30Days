#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    string s;
    
    void brackets(int i,int j,int n,int *bracket,char &name)
    {
    	if(i==j)
    	{
    		s+=name;
    		name++;
    		return;
    	}
    	s+='(';
    	brackets(i,bracket[i][j],n,bracket,name);
    	brackets(bracket[i][j]+1,j,n,bracket,name);
    	s+=')';
    }
    
    string matrixChainOrder(int p[], int n)
    {
        int m[n][n];
    	int bracket[n][n];
    	
    	for(int i=1;i<n;i++)
    	    m[i][i] = 0;
    	    
    	for(int L=2;L<n;L++)
    	{
    		for(int i=1;i<n-L+1;i++)
    		{
    			int j=i+L-1;
    			m[i][j]=INT_MAX;
    			for(int k=i;k<=j-1;k++)
    			{
    				int q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
    				if(q<m[i][j])
    				{
    					m[i][j]=q;
    					bracket[i][j] = k;
    				}
    			}
    		}
    	}
    	char name='A';
    	brackets(1,n-1,n,(int *)bracket,name);
    	return s;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int p[n];
        for(int i = 0;i < n;i++)
            cin>>p[i];
        
        Solution ob;
        cout<<ob.matrixChainOrder(p, n)<<"\n";
    }
    return 0;
}