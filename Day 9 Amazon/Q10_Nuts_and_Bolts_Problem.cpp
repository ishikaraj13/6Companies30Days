#include <bits/stdc++.h>
using namespace std;

class Solution{
public:	

	void matchPairs(char nuts[], char bolts[], int n) 
	{
	    map<char,int> m;
        m['!']=0;
        m['#']=0;
        m['$']=0;
        m['%']=0;
        m['&']=0;
        m['*']=0;
        m['@']=0;
        m['^']=0;
        m['~']=0;
        
        for(int i=0;i<n;i++)
        {
            m[nuts[i]]++;
            m[bolts[i]]++;
        }
        int i=0;
        for(auto it:m)
        {
            if(it.second==2)
            {
                nuts[i]=bolts[i]=it.first;
                i++;
            }
        }
        
	}

};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        char nuts[n], bolts[n];
        for (int i = 0; i < n; i++) {
            cin >> nuts[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> bolts[i];
        }
        Solution ob;
        ob.matchPairs(nuts, bolts, n);
        for (int i = 0; i < n; i++) {
            cout << nuts[i] << " ";
        }
        cout << "\n";
        for (int i = 0; i < n; i++) {
            cout << bolts[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}