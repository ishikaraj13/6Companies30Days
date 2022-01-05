#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool canPair(vector<int> nums, int k) 
    {
        
        int n=nums.size();
        if(n%2!=0)
            return 0;
            
        unordered_map<int,int> m;
        for(int i=0;i<n;i++)
        {
            nums[i]=nums[i]%k;
            m[nums[i]]++;
        }
        
        for(auto &it:m)
        {
            int temp=it.first;
            if(2*temp==k || temp==0)
            {
                if(it.second%2!=0)
                    return 0;
            }
            else if(m[temp]!=m[k-temp])
                    return 0;
          
        }
        
        return 1;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
} 