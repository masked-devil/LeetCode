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
    int getDiameter(TreeNode* root, int& maxD){
        if(root==NULL){
            return 0;
        }

        int leftDepth=getDiameter(root->left, maxD);
        int rightDepth=getDiameter(root->right,maxD);

        int currentD=leftDepth+rightDepth+1;

        maxD=max(maxD,currentD);

        return max(leftDepth, rightDepth)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int answer=0;
        getDiameter(root, answer);
        
        return answer-1;


    }
};