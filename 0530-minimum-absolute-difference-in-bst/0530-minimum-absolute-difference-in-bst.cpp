/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int minval=INT_MAX;
    int prev =0;
    bool hasprev=false;

public:
    int getMinimumDifference(TreeNode* root) {
        
        if(!root) return minval;
        getMinimumDifference(root->left);
        if(hasprev){
            minval=min(minval,root->val - prev);
        }
        prev=root->val;
        hasprev=true;
        getMinimumDifference(root->right);
        return minval;
    }
};