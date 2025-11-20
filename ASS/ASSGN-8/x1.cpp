#include <iostream>
using namespace std;

// TreeNode structure for VS Code
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
    void pre(TreeNode* root, int &sum){
        if(root == NULL) return;

        if(root->left != NULL){
            if(root->left->left == NULL && root->left->right == NULL){
                sum = sum + root->left->val;
            }
        }

        pre(root->left, sum);
        pre(root->right, sum);
    }

    int sumOfLeftLeaves(TreeNode* root){
        int sum = 0;
        pre(root, sum);
        return sum;
    }
};

int main(){
    // sample tree
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution s;

    int ans = s.sumOfLeftLeaves(root);

    cout << ans << endl;

    return 0;
}
