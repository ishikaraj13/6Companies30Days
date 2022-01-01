#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) 
    {
        long long temp=1,i=0,j=0,res=0;
        while(j<n)
        {
            temp=temp*a[j];
            while(i<=j && temp>=k)
            {
                temp=temp/a[i];
                i++;
            }
            if(temp<k)
            {
                res+=1+(j-i);
            }
            j++;
        }
        return res;
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}
