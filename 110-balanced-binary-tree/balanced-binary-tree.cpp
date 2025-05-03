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
    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }

        int leftHeight=height(root->left);
        int rightHeight=height(root->right);
        int maxHeight=max(leftHeight,rightHeight)+1;

        

        return maxHeight;



    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;
        }

        bool leftAns=isBalanced(root->left);
        bool rightAns=isBalanced(root->right);

        int heightDiff=abs(height(root->left)-height(root->right));

        if(leftAns && rightAns && heightDiff<=1){
            return true;
        }

        return false;
    }
};