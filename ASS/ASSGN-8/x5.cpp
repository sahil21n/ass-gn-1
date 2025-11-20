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
    TreeNode* solve(vector<int> &preorder, vector<int> &inorder, int start, int end, int &idx){

        if(start > end) return NULL;

        int rootval = preorder[idx];

        int i = start;
        for(; i <= end; i++){
            if(inorder[i] == rootval) break;
        }

        idx++;

        TreeNode* root = new TreeNode(rootval);

        root->left = solve(preorder, inorder, start, i - 1, idx);
        root->right = solve(preorder, inorder, i + 1, end, idx);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx = 0;
        int n = inorder.size();
        return solve(preorder, inorder, 0, n - 1, idx);
    }
};

int main(){
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder  = {9,3,15,20,7};

    Solution s;

    TreeNode* root = s.buildTree(preorder, inorder);

    if(root != NULL) cout << "Tree built successfully (Q5)\n";
    else cout << "Tree is empty\n";

    return 0;
}
