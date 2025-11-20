#include <iostream>
#include <vector>
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
        if(root == NULL) return 0;

        int lmax = levels(root->left);
        int rmax = levels(root->right);

        return 1 + max(lmax, rmax);
    }

    void preorder(TreeNode* root, vector<int>& ans, int level){
        if(root == NULL) return;

        ans[level] = root->val;

        preorder(root->left, ans, level + 1);
        preorder(root->right, ans, level + 1);
    }

    vector<int> rightSideView(TreeNode* root){
        int h = levels(root);
        vector<int> ans(h, 0);

        preorder(root, ans, 0);

        return ans;
    }
};

int main(){
   
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);

    Solution s;

    vector<int> res = s.rightSideView(root);

    cout << "Right side view: ";
    for(int i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}
