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
    int solveUsingTab(vector<int>& nums){
        int n = nums.size();
        vector<int> dp(n,-1);
        dp[n-1] = nums[n-1];
        if(n == 1) return dp[0];
        dp[n-2] = max(nums[n-1], nums[n-2]);

        for(int i = n-3; i>=0; i--){
            int inc = nums[i] + dp[i+2];
            int exc = dp[i+1];

            dp[i] = max(inc, exc);
        }

        return dp[0];
    }
    int rob(vector<int>& nums) {
        // int ans = solveUsingRecursion (nums, 0);
        // int n = nums.size();
        // vector<int> dp(n, -1);
        // int ans = solveUsingMem(nums, 0 ,dp);
        int ans = solveUsingTab(nums);
        return ans;
    }
};