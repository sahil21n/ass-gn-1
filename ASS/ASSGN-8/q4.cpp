
#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x){
        val = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    TreeNode* prev;
    bool flag;

    Solution(){
        prev = NULL;
        flag = true;
    }

    void inorder(TreeNode* root){
        if(root == NULL) return;

        inorder(root->left);

        if(prev != NULL){
            if(root->val <= prev->val){
                flag = false;
                return;
            }
        }

        prev = root;

        inorder(root->right);
    }

    bool isValidBST(TreeNode* root){
        prev = NULL;
        flag = true;

        inorder(root);

        return flag;
    }
};

int main(){
    

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);

    Solution s;

    bool ok = s.isValidBST(root);

    if(ok == true) cout<<"Valid BST\n";
    else cout<<"Not a BST\n";

    return 0;
}
