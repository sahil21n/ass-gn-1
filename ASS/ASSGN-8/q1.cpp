#include <iostream>
#include <queue>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int x){
        val=x;
        left=NULL;
        right=NULL;
    }
};

Node* buildTree(int a[], int n){
    if(n==0) return NULL;
    if(a[0]==-1) return NULL;

    Node* root=new Node(a[0]);
    queue<Node*> q;
    q.push(root);

    int i=1;

    while(!q.empty() && i<n){
        Node* cur=q.front();
        q.pop();

        if(i<n){
            if(a[i]!=-1){
                cur->left=new Node(a[i]);
                q.push(cur->left);
            }
            i++;
        }
        if(i<n){
            if(a[i]!=-1){
                cur->right=new Node(a[i]);
                q.push(cur->right);
            }
            i++;
        }
    }
    return root;
}

void preorder(Node* root){
    if(root==NULL) return;
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root){
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

void postorder(Node* root){
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->val<<" ";
}

int main(){
    int n;
    cin>>n;

    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];

    Node* root=buildTree(a,n);

    preorder(root); cout<<endl;
    inorder(root); cout<<endl;
    postorder(root); cout<<endl;
}
