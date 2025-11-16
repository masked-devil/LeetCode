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
public:
    bool solve(TreeNode* root, long long start, long long end){
        if(root==NULL){
            return true;
        }

        if(root->val <= start || root->val >= end){
            return false;
        }

        bool left=solve(root->left, start, root->val);
        bool right=solve(root->right, root->val, end);

        return left && right;

    }
    bool isValidBST(TreeNode* root) {

        return solve(root, LONG_MIN, LONG_MAX);
        
    }
};