#include <bits/stdc++.h>

using namespace std;

class Solution{
public:
    int *findTwoElement(int *arr, int n) 
    {
        // code here
        int *ans = new int[2];
        for(int i=0;i<n;i++)
        {
            int index=abs(arr[i])-1;
            if(arr[index]<0)
                ans[0]=index+1;
            else
                arr[index]=-arr[index];
        }
        
        for(int i=0;i<n;i++)
        {
            if(arr[i]>0)
                ans[1]=i+1;
        }
        return ans;
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  