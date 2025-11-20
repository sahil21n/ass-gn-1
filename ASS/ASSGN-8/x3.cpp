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
    int levels(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        int llevels = levels(root->left);
        int rlevels = levels(root->right);

        return 1 + max(llevels, rlevels);
    }

    int maxDepth(TreeNode* root){
        return levels(root);
    }
};

int main(){
    // sample tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);

    Solution s;

    int depth = s.maxDepth(root);

    cout << "Max Depth = " << depth << endl;

    return 0;
}
