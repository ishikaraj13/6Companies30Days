#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long

class Solution
{
public:	

	ull getNthUglyNo(int n) 
	{
	    vector<ull> ans;
        ull two=0,three=0,five=0;
        ans.push_back(1);
        for(int i=1;i<n;i++)
        {
            ull min_val=min({2*ans[two],3*ans[three],5*ans[five]});
            ans.push_back(min_val);
            if(2*ans[two]==min_val) 
                two++;
            if(3*ans[three]==min_val) 
                three++;
            if(5*ans[five]==min_val) 
                five++;
        }
        return ans.back();
	}
};

int main()
{
    int t;
    cin >> t;
    while1(t--) 
    {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.getNthUglyNo(n);
        cout << ans << "\n";
    }
    return 0;
}