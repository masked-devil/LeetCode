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
    pair<bool, pair<long long,long long>> solve(TreeNode* root){
        if(root==NULL){
            return {true, {LONG_MIN, LONG_MAX}};
        }

        pair<bool, pair<long long,long long>> left=solve(root->left);
        pair<bool, pair<long long,long long>> right=solve(root->right);

        bool isLeftBST = left.first;
        bool isRightBST = right.first;

        bool isGreaterThanLeft = root->val > left.second.first;
        bool isLessThanRight = root->val < right.second.second;

        bool isBST = isLeftBST && isRightBST && isGreaterThanLeft && isLessThanRight;

        long long maxi = max({left.second.first, right.second.first, 1LL* root->val});
        long long mini = min({left.second.second,right.second.second, 1LL* root->val});

        return {isBST, {maxi,mini}};

    }
    bool isValidBST(TreeNode* root) {
        pair<bool, pair<long long,long long>> ans=solve(root);

        return ans.first;
        
    }
};