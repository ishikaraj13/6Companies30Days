#include<bits/stdc++.h>
using namespace std;

    int minSubArrayLen(int target, vector<int>& a) 
    {
        int n=a.size();
        int i=0,j=0,res=INT_MAX,tempsum=0;
        while(j<n)
        {
            tempsum+=a[j];
            while(tempsum>=target)
            {
                res=min(res,j-i+1);
                tempsum-=a[i];
                i++;
            }
            j++;
        }
        if(res==INT_MAX)
            return 0;
        return res;  
    }

int main()
{
    int n,target;
    cin>>n>>target;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<minSubArrayLen(target,arr);
    return 0;
}