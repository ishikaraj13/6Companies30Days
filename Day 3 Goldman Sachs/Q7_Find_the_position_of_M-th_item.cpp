#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findPosition(int N, int M , int K) 
    {
        if( (K+M-1) % N == 0)
            return N;
        return (K+M-1) % N;
    }
};

int main() 
{
    int t;
    cin >> t;
    while (t--) {
        int N,M,K;
        
        cin>>N>>M>>K;

        Solution ob;
        cout << ob.findPosition(N,M,K) << endl;
    }
    return 0;
} 