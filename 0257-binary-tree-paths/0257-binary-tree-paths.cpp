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
private:
    void findpath(TreeNode* root,vector<string>& res,string temp){
        temp+=to_string(root->val);
        if(!root) res.push_back(temp);
        if(root->left) findpath(root->left,res,temp+"->");
        if(root->right) findpath(root->right,res,temp+"->");
        if(!root->left && !root->right){
            res.push_back(temp);
        }
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        findpath(root,res,"");
        return res;

    }
};