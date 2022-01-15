#include <bits/stdc++.h>
#include <string>
using namespace std;

class Solution
{
    public:
    
    vector<string> v={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> ans;
    
    void sol(int a[], int n,string& temp,int i)
    {
        if(i==n)
            ans.push_back(temp);
        else
        {
            for(char c: v[a[i]-2] )
            {
                temp.push_back(c);
                sol(a,n,temp,i+1);
                temp.pop_back();
            }
        }
        
    }
    vector<string> possibleWords(int a[], int n)
    {
        //Your code here
        if(n==0)
            return ans;
        string temp="";
        sol(a,n,temp,0);
        return ans;
    }
};


int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}  