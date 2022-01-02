#include<bits/stdc++.h>
using namespace std;

string gcdOfStrings(string str1, string str2) 
{
    if(str1+str2!=str2+str1)
        return "";
        
    return str1.substr(0, gcd(str1.size(), str2.size()));

}
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    cout<<gcdOfStrings(s1,s2);
    return 0;
}
