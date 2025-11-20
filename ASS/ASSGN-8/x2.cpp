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
    vector<TreeNode*> solve(int start, int end){
        if(start > end){
            vector<TreeNode*> temp;
            temp.push_back(NULL);
            return temp;
        }

        vector<TreeNode*> ans;

        for(int i = start; i <= end; i++){
            
            vector<TreeNode*> left_bsts = solve(start, i-1);
            vector<TreeNode*> right_bsts = solve(i+1, end);

            for(int l = 0; l < left_bsts.size(); l++){
                for(int r = 0; r < right_bsts.size(); r++){
                    
                    TreeNode* root = new TreeNode(i);
                    root->left = left_bsts[l];
                    root->right = right_bsts[r];

                    ans.push_back(root);
                }
            }
        }
        return ans;
    }

    vector<TreeNode*> generateTrees(int n){
        if(n == 0){
            vector<TreeNode*> empty;
            return empty;
        }
        return solve(1, n);
    }
};

int main(){
    Solution s;
    int n = 3;

    vector<TreeNode*> res = s.generateTrees(n);

    cout << "Generated " << res.size() << " unique BSTs for n=" << n << endl;

    return 0;
}
