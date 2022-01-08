
#include<bits/stdc++.h>
using namespace std;

    int longestMountain(vector<int>& a) 
    {
        int n=a.size();
        int i=1,res=0;
        
        while(i<n)
        {
            int before=0,after=0;
            while(i<n && a[i-1]==a[i])
                i++;
            while(i<n && a[i-1]<a[i])
            {
                before++;
                i++;
            }
            while(i<n && a[i-1]>a[i])
            {
                after++;
                i++;
            }
            if(before && after)
                res=max(res,after+before+1);
        }
        return res;
    }

    int main() 
    {
  
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) 
            cin >> arr[i];
        
        cout<<longestMountain(arr);
        
        return 0;
    }