#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
Node* convert(int arr[],int l,int r)
{
    if(l>r) return NULL;
    int mid=(l+r)/2;
    Node* root=new Node(arr[mid]);
    Node* leftRoot=convert(arr,l,mid-1);
    Node* rightRoot=convert(arr,mid+1,r);
    root->left=leftRoot;
    root->right=rightRoot;
    return root;
}
void print_levelOrder(Node* root)
{
    queue<Node*>q;
    q.push(root);
    while(!q.empty())
    {
        Node* pr=q.front();
        q.pop();
       cout<<pr->val<<" ";
        if(pr->left) q.push(pr->left);
         if(pr->right) q.push(pr->right);
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];//Sorted array input dite hobe
    Node* root=convert(arr,0,n-1);
    print_levelOrder(root);
    cout<<endl;
}