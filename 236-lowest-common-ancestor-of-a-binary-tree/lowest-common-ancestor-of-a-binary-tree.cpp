/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL || root==p || root==q){
            return root;
        }

        TreeNode*  optionLeft = lowestCommonAncestor(root->left,p,q);
        TreeNode*  optionRight = lowestCommonAncestor(root->right,p,q);

        if(optionLeft && optionRight){
            return root;
        }
        else{
            return optionLeft?optionLeft:optionRight;
        }
    }
};