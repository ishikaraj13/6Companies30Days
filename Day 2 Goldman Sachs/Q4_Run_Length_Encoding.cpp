#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}

string encode(string src)
{     
    string res="";
    int n=src.length();
    for(int i=0;i<n;i++)
    {
        char c=src[i];
        int temp=0;
        while(src[i]==c)
        {
            temp++;
            i++;
        }
        res=res+c;
        res+=(temp+'0');
        i--;
    }
    return res;
    
}     