#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<vector<string>> res;
    vector<string> temp;
    struct TrieNode
    {
        unordered_map<char,TrieNode*> child;
        bool isLast;
        
        TrieNode()
        {
            for(char i='a';i<='z';i++)
            {
                child[i]=NULL;
                isLast=false;
            }
        }
    };
    TrieNode* root=NULL;
    void insert(string s)
    {
        int l=s.length();
        TrieNode* itr=root;
        for(int i=0;i<l;i++)
        {
            TrieNode* nextNode=itr->child[s[i]];
            if(nextNode==NULL)
            {
                nextNode = new TrieNode();
                itr->child[s[i]]=nextNode;
            }
            itr=nextNode;
            if(i==l-1)
                itr->isLast=true;
        }
    }
    void helper(TrieNode *curNode, string prefix)
    {
        
        if(curNode->isLast)
            temp.push_back(prefix);
      
        for(char i='a';i<='z';i++)
        {
            TrieNode *nextNode = curNode->child[i];
            if(nextNode!=NULL)
                helper(nextNode,prefix+(char)i);
        }
    }
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        root=new TrieNode();
  
        for(int i=0;i<n;i++)
            insert(contact[i]);
           
        TrieNode *prevNode = root;
  
        string prefix="";
        int len=s.length(),i;

        for(i=0;i<len;i++)
        {
            prefix+=(char)s[i];
            char lastChar=prefix[i];
      
            TrieNode *curNode = prevNode->child[lastChar];
            if(curNode==NULL)
            {
                res.push_back({"0"});
                i++;
                break;
            }
            
            helper(curNode,prefix);
            res.push_back(temp);
            temp.clear();
            prevNode=curNode;
        }
     
        for (;i<len;i++)
        {
            prefix+=(char)s[i];
            res.push_back({"0"});
        } 
        
        return res;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}  