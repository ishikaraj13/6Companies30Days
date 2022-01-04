#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    priority_queue<int, vector<int>, greater<int>> pq;
    while(n--)
    {
        int temp;
        cin>>temp;
        if(pq.size()<10)
            pq.push(temp);
        else 
        {
            if(temp>pq.top())
            {
                pq.push(temp);
                pq.pop();
            }
        }
    }
    vector<int> res;
    while(!pq.empty())
    {
        res.push_back(pq.top());
        pq.pop();
    }
    for(int i:res)
    {
        cout<<i<<" ";
    }
    return 0;
}