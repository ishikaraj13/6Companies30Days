#include <bits/stdc++.h>
using namespace std;

struct Node 
{
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node *buildTree(string str) 
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) 
    {
        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") 
        {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") 
        {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


class Solution {
  public:
  
    Node* target=NULL;
    
    void findnode(Node* root,int k)
    {
        if(root==NULL)
            return;
            
        if(root->data==k)
        {
            target=root;
            return;
        }
        
        findnode(root->left,k);
        findnode(root->right,k);
    }
    
    int minTime(Node* root, int k) 
    {
        if(root==NULL || (root->left==NULL && root->right==NULL))
            return 0;
            
        map<Node*,Node*> m;
        map<Node*,bool> visit;
        queue<Node*> q;
        q.push(root);
        m[root]=NULL;
        visit[root]=0;
        while(!q.empty())
        {
            Node* temp=q.front();
            q.pop();
            if(temp->left)
            {
                q.push(temp->left);
                m[temp->left]=temp;
                visit[temp->left]=0;
            }
            if(temp->right)
            {
                q.push(temp->right);
                m[temp->right]=temp;
                visit[temp->right]=0;
            }
        }
        
        findnode(root,k);
        if(target==NULL)
            return 0;
            
        int res=0;
        
        q.push(target);
        visit[target]=1;
        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
                Node* temp=q.front();
                q.pop();
                if(temp->left && !visit[temp->left])
                {
                    q.push(temp->left);
                    visit[temp->left]=1;
                }
                if(temp->right && !visit[temp->right])
                {
                    q.push(temp->right);
                    visit[temp->right]=1;
                }
                if(m[temp] && !visit[m[temp]])
                {
                    q.push(m[temp]);
                    visit[m[temp]]=1;
                }
            }
            res++;
        }
        return res-1;
        
    }
};

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        int target;
        cin>>target;

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }
    return 0;
}