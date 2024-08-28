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
Node *convert(int a[], int n, int l, int r)
{

// left যদি right থেকে বড় হয় তাহলে return করবো null
    if (l > r)
        return NULL;
//এর পর mid calculate করা হয়েছে।
    int mid = (l + r) / 2;
// Mid দিয়ে new root create করা হয়েছে
    Node *root = new Node(a[mid]);
//এর পর right এ একবার এবং left এ একবার traverse করবো
    Node *leftRoot = convert(a, n, l, mid - 1);
    Node *rootRight = convert(a, n, mid + 1, r);

//এখন left e রাখবো left subtree right এ রাখবো right subtree
    root->left = leftRoot;
    root->right = rootRight;
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
bool search(Node* root,int x)
{
    if(root==NULL) return false;
    if(root->val==x) return true;
    if(x>root->val) return search(root->right,x);
    else return search(root->left,x);
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    Node* root=convert(arr,n,0,n-1);
   // print_levelOrder(root);
    int x;
    cout<<"Input searching value"<<endl;
    cin>>x;
    if(search(root,x)) cout<<"Found"<<endl;
    else cout<<"Not Found"<<endl;
}
