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

Node* recSearch(Node* root, int key){
    if(root==NULL) return NULL;
    if(root->val==key) return root;

    if(key < root->val){
        return recSearch(root->left,key);
    }
    else{
        return recSearch(root->right,key);
    }
}

Node* itSearch(Node* root, int key){
    while(root!=NULL){
        if(root->val==key) return root;

        if(key < root->val){
            root=root->left;
        }
        else{
            root=root->right;
        }
    }
    return NULL;
}

Node* findMin(Node* root){
    if(root==NULL) return NULL;
    while(root->left!=NULL) root=root->left;
    return root;
}

Node* findMax(Node* root){
    if(root==NULL) return NULL;
    while(root->right!=NULL) root=root->right;
    return root;
}

Node* successor(Node* root, int key){
    Node* suc=NULL;
    Node* cur=root;

    while(cur!=NULL){
        if(key < cur->val){
            suc=cur;
            cur=cur->left;
        }
        else if(key > cur->val){
            cur=cur->right;
        }
        else{
            if(cur->right!=NULL){
                return findMin(cur->right);
            }
            return suc;
        }
    }
    return NULL;
}

Node* predecessor(Node* root, int key){
    Node* pre=NULL;
    Node* cur=root;

    while(cur!=NULL){
        if(key > cur->val){
            pre=cur;
            cur=cur->right;
        }
        else if(key < cur->val){
            cur=cur->left;
        }
        else{
            if(cur->left!=NULL){
                return findMax(cur->left);
            }
            return pre;
        }
    }
    return NULL;
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

    Node* r1=recSearch(root,key);
    if(r1!=NULL) cout<<1; else cout<<0;
    cout<<endl;

    Node* r2=itSearch(root,key);
    if(r2!=NULL) cout<<1; else cout<<0;
    cout<<endl;

    Node* mx=findMax(root);
    if(mx!=NULL) cout<<mx->val; else cout<<-1;
    cout<<endl;

    Node* mn=findMin(root);
    if(mn!=NULL) cout<<mn->val; else cout<<-1;
    cout<<endl;

    Node* s=successor(root,key);
    if(s!=NULL) cout<<s->val; else cout<<-1;
    cout<<endl;

    Node* p=predecessor(root,key);
    if(p!=NULL) cout<<p->val; else cout<<-1;
    cout<<endl;
}
