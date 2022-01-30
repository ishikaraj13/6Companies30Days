#include <bits/stdc++.h>
using namespace std;


class Solution{
    public:
    vector<vector<int> > fourSum(vector<int> &a, int k) 
    {
        int n=a.size();
        vector<vector<int>> res;
        
        if(n<4)
            return res;
        
        sort(a.begin(),a.end()); 
        for(int i=0;i<n-3;i++)
        {
            for(int j=i+1;j<n-2;j++)
            {
                int l=j+1,r=n-1;
                while(l<r)
                {
                    if(a[i]+a[j]+a[l]+a[r]==k)
                    {
                        vector<int> quad={a[i],a[j],a[l],a[r]};
                        res.push_back(quad);
                        while(l<r && a[l]==quad[2])
                            l++;
                        while(l<r && a[r]==quad[3])
                            r--;
                    }
                    else if(a[i]+a[j]+a[l]+a[r]<k)
                        l++;
                    else
                        r--;
                }
                while(j+1<n && a[j+1]==a[j])
                    j++;
            }
            while(i+1<n && a[i+1]==a[i])
                    i++;
        }
        return res;
        
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}