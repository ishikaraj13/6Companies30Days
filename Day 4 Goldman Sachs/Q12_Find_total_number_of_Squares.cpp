#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    // for 5*5 board, considering each cell of board as top left cell of each square
    // we can have 5*5 1 unit squares
    // for 2 unit squares there are 4*4 possibilities of top left cell
    // for 3 unit squares 3*3 
    // for 4 unit sqaures 2*2
    // for 5 unit squares 1*1
    // ans=4*4+3*3+2*2+1*1
    cout<<n*(n+1)*(2*n+1)/6;
    return 0;
}