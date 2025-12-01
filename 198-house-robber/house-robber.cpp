class Solution {
public:
    int solve(vector<int>& nums, int index, vector<int>& dp){
        if(index>=nums.size()){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        //include
        int inc=nums[index] + solve(nums, index+2,dp);
        //exclude
        int exc=solve(nums,index+1,dp);

        dp[index] = max(inc,exc);
        return dp[index];
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1, -1);
        int ans = solve(nums,0, dp);
        return ans;
        
    }
};