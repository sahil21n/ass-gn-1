#include<iostream>
#include<algorithm>
using namespace std;
class node{
    public:
    int val;
    node* right;
    node* left;

    node(int val){
        this->val=val;
        right=left=NULL;
    } 



};

void display(node*root ){
    if(root==NULL) return;
    cout<<root->val<<" ";    
    display(root->right);    
    display(root->left);

}

int size(node* root){
    if(root==NULL) return 0;
   int ans=1+size(root->right)+size(root->left);

   return ans;

    
}

int sum(node* root){
    if(root==NULL) return 0;

    int ans=(root->val)+sum(root->right)+sum(root->left);

    return ans;
}

int maximum(node* root){
    if(root==NULL) return 0;
    int leftmax=maximum(root->left);
    int rightmax=maximum(root->right);

    return max(root->val,max(leftmax,rightmax));
}

int levels(node* root){
    if(root==NULL) return 0;
    int leftlevel=levels(root->left);
    int rightlevel=levels(root->right);

    return 1+max(leftlevel,rightlevel);
}
int main(){

    node*root=new node(1);
    node*a=new node(2);node*b=new node(3);node*c=new node(4);node*d=new node(5);

    node*e=new node(6);

    root->left=a;
    root->right=b;

    b->right=e;

    a->left=c;
    a->right=d; 

    display(root);

    cout<<endl;

    cout<< size(root)<<endl;

    cout<< sum(root)<<endl;

    cout<<maximum(root)<<endl;


    cout<<levels(root)<<endl;
    

}