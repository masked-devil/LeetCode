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
    bool isExist(TreeNode* root, TreeNode* x){
        if(root==NULL){
            return false;
        }
        if(root==x){
            return true;
        }
        return isExist(root->left,x) || isExist(root->right,x);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL){
            return NULL;
        }
        if(root==p || root==q){
            return root;
        }
        bool pLeft=isExist(root->left, p);
        bool pRight=!pLeft;

        bool qLeft=isExist(root->left, q);
        bool qRight=!qLeft;

        if(pLeft==qLeft){
            if(pLeft){
                return lowestCommonAncestor(root->left, p, q);
            }
            else{
                return lowestCommonAncestor(root->right, p, q);
            }
        }
        else{
            return root;
        }
    }
};