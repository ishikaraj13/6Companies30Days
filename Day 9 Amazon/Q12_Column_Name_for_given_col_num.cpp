#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    string colName (long long int c)
    {
        // your code here
        vector<char> v;
        while(c>0)
        {
            c--;
            long long int mod=c%26;
            v.push_back('A'+mod);
            c=c/26;
        }
        string s="";
        for(long long int i=v.size()-1;i>=0;i--)
        {
            s+=v[i];
        }
        return s;
    }
};

int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}