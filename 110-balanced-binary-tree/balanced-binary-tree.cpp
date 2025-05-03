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
    int height(TreeNode* root, bool& answer){
        if(root==NULL){
            return 0;
        }

        int leftHeight=height(root->left, answer);
        int rightHeight=height(root->right, answer);
        int maxHeight=max(leftHeight,rightHeight)+1;

        if(abs(leftHeight-rightHeight)>1){
            answer=false;
        }

        return maxHeight;



    }
    bool isBalanced(TreeNode* root) {
        bool answer=true;

        height(root, answer);

        return answer;
    }
};