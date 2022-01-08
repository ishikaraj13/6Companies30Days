#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> a, int n, int k) 
    {
        
        vector<int> res;
        deque<int> q;
        
        for(int i=0;i<n;i++)
        {
            while(!q.empty() && i-q.front()>=k)
                q.pop_front();
            while(!q.empty() && a[q.back()]<=a[i])
                q.pop_back();
            q.push_back(i);
            if(i>=k-1)
                res.push_back(a[q.front()]);
        }
        return res;
    }
};

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}  