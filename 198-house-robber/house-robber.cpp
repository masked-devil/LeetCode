class Solution {
public:
    int solveUsingRecursion(vector<int>& nums, int index){
        int n = nums.size();
        if(index>=n){
            return 0;
        }

        int inc = nums[index] + solveUsingRecursion(nums, index+2);
        int exc = solveUsingRecursion(nums, index+1);

        int ans = max(inc,exc);

        return ans;
    }
    int solveUsingMem(vector<int>& nums,int index, vector<int>& dp){
        int n = nums.size();
        if(index>=n){
            return 0;
        }

        if(dp[index]!=-1){
            return dp[index];
        }

        int inc = nums[index] + solveUsingMem(nums, index+2, dp);
        int exc = solveUsingMem(nums, index+1, dp);

        dp[index] = max(inc,exc);

        return dp[index];
    }
    int rob(vector<int>& nums) {
        // int ans = solveUsingRecursion (nums, 0);
        int n = nums.size();
        vector<int> dp(n, -1);
        int ans = solveUsingMem(nums, 0 ,dp);
        return ans;
    }
};