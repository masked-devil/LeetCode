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

    int solveUsingTab(vector<int>& nums){
        int n=nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for(int i=n-1; i>=0;i--){
            for(int j = i-1; j>=-1; j--){ //imp
                int inc = (j == -1 || nums[i]>nums[j]) ? 1+dp[i+1][i+1] /* imp */ : 0;
                int exc = dp[i+1][j+1]; //imp

                dp[i][j+1] = max(inc,exc); //imp
            }
        }

        return dp[0][0];
    }

    int solveUsingSO(vector<int>& nums){
        int n=nums.size();
        vector<int> next(n+1,0);
        vector<int> curr(n+1,0);

        for(int i=n-1; i>=0;i--){
            for(int j = i-1; j>=-1; j--){ //imp
                int inc = (j == -1 || nums[i]>nums[j]) ? 1+next[i+1] /* imp */ : 0;
                int exc = next[j+1]; //imp

                curr[j+1] = max(inc,exc); //imp
            }
            next = curr;
        }

        return next[0];
    }

    int lengthOfLIS(vector<int>& nums) {
        // return solveUsingRec(nums, 0, -1);
        // int n = nums.size();
        // vector<vector<int>> dp(n+1, vector<int>(n+1 ,-1));
        // return solveUsingMem(nums, 0, -1, dp);
        // return solveUsingTab(nums);
        return solveUsingSO(nums);
    }
};