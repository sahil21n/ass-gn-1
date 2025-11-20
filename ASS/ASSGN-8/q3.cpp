#include <iostream>
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

Node* insertNode(Node* root, int x){
    if(root==NULL){
        root=new Node(x);
        return root;
    }
    if(x < root->val){
        root->left=insertNode(root->left,x);
    }
    else if(x > root->val){
        root->right=insertNode(root->right,x);
    }
    return root;
}

Node* findMin(Node* root){
    while(root->left!=NULL) root=root->left;
    return root;
}

Node* deleteNode(Node* root, int key){
    if(root==NULL) return NULL;

    if(key < root->val){
        root->left=deleteNode(root->left,key);
    }
    else if(key > root->val){
        root->right=deleteNode(root->right,key);
    }
    else{
        if(root->left==NULL){
            Node* r=root->right;
            delete root;
            return r;
        }
        if(root->right==NULL){
            Node* l=root->left;
            delete root;
            return l;
        }
        Node* mn=findMin(root->right);
        root->val=mn->val;
        root->right=deleteNode(root->right,mn->val);
    }
    return root;
}

void inorder(Node* root){
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

int maxDepth(Node* root){
    if(root==NULL) return 0;
    int L=maxDepth(root->left);
    int R=maxDepth(root->right);

    if(L>R) return L+1;
    else return R+1;
}

int minDepth(Node* root){
    if(root==NULL) return 0;

    if(root->left==NULL && root->right!=NULL){
        return 1+minDepth(root->right);
    }
    if(root->left!=NULL && root->right==NULL){
        return 1+minDepth(root->left);
    }

    int L=minDepth(root->left);
    int R=minDepth(root->right);

    if(L<R) return L+1;
    else return R+1;
}

int main(){
    int n;
    cin>>n;

    Node* root=NULL;
    int x;

    for(int i=0;i<n;i++){
        cin>>x;
        root=insertNode(root,x);
    }

    int key;
    cin>>key;

    root=deleteNode(root,key);

    inorder(root); cout<<endl;

    cout<<maxDepth(root)<<endl;
    cout<<minDepth(root)<<endl;
}
