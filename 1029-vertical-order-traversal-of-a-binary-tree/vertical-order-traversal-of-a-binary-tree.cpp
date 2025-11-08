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
    void insertInSorted(vector<int>& nums, int number){
        int i=nums.size()-1;
        nums.push_back(-1);

        while(i>=0 && number<nums[i]){
            nums[i+1]=nums[i];
            i--;
        }

        nums[i+1]=number;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<int>> mp;
        map<int, vector<int>> mp2;

        queue<pair<TreeNode*, int>> q;
        q.push({root,0});
        q.push({NULL,1001});

        while(!q.empty()){
            pair<TreeNode*, int> temp=q.front();
            q.pop();

            TreeNode* frontNode=temp.first;
            int level=temp.second;
            if(frontNode){
                insertInSorted(mp2[level], frontNode->val);

                if(frontNode->left){
                    q.push({frontNode->left, level-1});
                }
                if(frontNode->right){
                    q.push({frontNode->right, level+1});
                }
            }
            else{
                if(!q.empty()){
                    q.push({NULL,1001});
                }

                for(auto x:mp2){
                    int level = x.first;
                    for (auto y:x.second){
                        mp[level].push_back(y);
                    }
                }
                mp2.clear();
            }
            
        }

        vector<vector<int>> ans;

        for(auto x:mp){
            ans.push_back(x.second);
        }

        return ans;
    }
};