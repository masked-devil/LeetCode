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
    TreeNode* inorderPredecessor(TreeNode* root){
        if(root==NULL){
            return NULL;
        }

        if(root->right == NULL){
            return root;
        }

        return inorderPredecessor(root->right);
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
            return NULL;
        }

        if(root->val == key){
            //case-1: leaf
            if(root->left==NULL && root->right==NULL){
                delete root;
                return NULL;
            }
            
            //case-2: left-only-null
            else if(root->left==NULL && root->right!=NULL){
                TreeNode* childSubtree = root->right;
                delete root;
                return childSubtree;
            }

            //case-3: right-only-null
            else if(root->right==NULL && root->left!=NULL){
                TreeNode* childSubtree = root->left;
                delete root;
                return childSubtree;
            }

            //case-4: both-not-null
            else{
                TreeNode* predecessor=inorderPredecessor(root->left);
                root->val=predecessor->val;
                root->left=deleteNode(root->left, predecessor->val);
                return root;
            }
        }
        else if(root->val > key){
            root->left = deleteNode(root->left, key);
        }
        else{
            root->right = deleteNode(root->right, key);
        }

        return root;
    }
};