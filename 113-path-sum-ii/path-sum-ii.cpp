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
    void checkPath(TreeNode* root, int targetSum, vector<vector<int>>& paths, vector<int>& path ){
        if(root==NULL){
            return;
        }
        path.push_back(root->val);
        if(root->left==NULL && root->right==NULL && root->val==targetSum){
            paths.push_back(path);
        }
        checkPath(root->left, targetSum-(root->val), paths, path);
        checkPath(root->right, targetSum-(root->val), paths, path);
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;

        checkPath(root, targetSum, ans, path);

        return ans;
    }
};