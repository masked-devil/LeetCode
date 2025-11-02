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
    void solve(TreeNode* root, int targetSum, vector<int>& path, vector<vector<int>>& paths){
        if(root==NULL){
            return;
        }
        path.push_back(root->val);

        if(root->left==NULL && root->right==NULL && root->val==targetSum){
            paths.push_back(path);
            path.pop_back();
            return;
        }

        solve(root->left, targetSum-root->val, path, paths);
        solve(root->right, targetSum-root->val, path, paths);

        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        vector<vector<int>> paths;

        solve(root, targetSum, path, paths);

        return paths;
    }
};