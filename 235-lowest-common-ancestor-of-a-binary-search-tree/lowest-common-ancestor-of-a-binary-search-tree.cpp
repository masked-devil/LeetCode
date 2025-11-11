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
        if(root==p || root==q){
            return root;
        }

        bool isFirstLeft = root->val > p->val;
        bool isSecondLeft = root->val > q->val;

        if(isFirstLeft != isSecondLeft){
            return root;
        }

        if(isFirstLeft){
            return lowestCommonAncestor(root ->left,p,q);
        }
        else{
            return lowestCommonAncestor(root ->right,p,q);
        }


    }
};