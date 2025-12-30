class Solution {
public:
    int solveMem(vector<int>& coins, int amount, vector<int>&dp){
        if(amount<0){
            return INT_MAX;
        }
        if(amount == 0){
            return 0;
        }

        if(dp[amount]!=-1){
            return dp[amount];
        }

        int mini = INT_MAX;
        for(auto coin:coins){
            int recAns = solveMem(coins, amount - coin, dp);
            if(recAns!=INT_MAX) recAns++;
            mini = min(mini, recAns);
        }
        dp[amount]=mini;
        return dp[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, -1);
        int ans = solveMem(coins, amount,dp);
        if(ans==INT_MAX) return -1;

        return ans;
    }
};