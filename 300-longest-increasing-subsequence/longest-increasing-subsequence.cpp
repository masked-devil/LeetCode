class Solution {
public:
    int solveUsingRec(vector<int>& nums, int curr, int prev){
        if(curr>=nums.size()){
            return 0;
        }

        int inc = (prev == -1 || nums[curr]>nums[prev]) ? 1+solveUsingRec(nums, curr+1, curr) : 0;
        int exc = solveUsingRec(nums, curr+1, prev);

        return max(inc,exc);
    }

    int solveUsingMem(vector<int>& nums, int curr, int prev, vector<vector<int>>& dp){
        if(curr>=nums.size()){
            return 0;
        }

        if(dp[curr][prev+1] != -1){
            return dp[curr][prev+1];
        }

        int inc = (prev == -1 || nums[curr]>nums[prev]) ? 1+solveUsingMem(nums, curr+1, curr, dp) : 0;
        int exc = solveUsingMem(nums, curr+1, prev, dp);

        dp[curr][prev+1] = max(inc,exc);

        return dp[curr][prev+1];
    }

    int lengthOfLIS(vector<int>& nums) {
        // return solveUsingRec(nums, 0, -1);
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1 ,-1));
        return solveUsingMem(nums, 0, -1, dp);
    }
};