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
    void solve(TreeNode* root, vector<int>& inorder, bool& ans){
        if(root == NULL){
            return;
        }


        if(ans)solve(root->left, inorder, ans);
        if(!inorder.empty() && root->val <= inorder[inorder.size()-1]){
            ans=false;
            return;
        }
        inorder.push_back(root->val);
        if(ans) solve(root->right, inorder, ans);
    }
    bool isValidBST(TreeNode* root) {
        bool ans = true;
        vector<int> inorder;

        solve(root, inorder, ans);

        return ans;


    }
};