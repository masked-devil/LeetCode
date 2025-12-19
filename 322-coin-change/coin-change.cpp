class Solution {
public:
    int solveUsingRecursion(vector<int>& coins, int amount){
        if(amount == 0){
            return 0;
        }
        if(amount < 0){
            return INT_MAX;
        }
        int minCoins = INT_MAX;
        for(auto coin:coins){
            int ans = solveUsingRecursion(coins, amount - coin);
            if(ans!=INT_MAX) ans++;

            minCoins = min(ans, minCoins);
        }

        return minCoins;
    }
    int solveUsingMem(vector<int>& coins, int amount, vector<int>& dp){
        if(amount == 0){
            return 0;
        }
        if(amount < 0){
            return INT_MAX;
        }

        if(dp[amount]!=-1){
            return dp[amount];
        }

        int minCoins = INT_MAX;
        for(auto coin:coins){
            int ans = solveUsingMem(coins, amount - coin, dp);
            if(ans!=INT_MAX){
                ans++;
            }

            minCoins = min(minCoins, ans);
        }

        dp[amount] = minCoins;

        return dp[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        // int ans = solveUsingRecursion(coins,amount);
        // if(ans == INT_MAX) return -1;

        vector<int> dp(amount+1, -1);
        int ans = solveUsingMem(coins, amount, dp);
        if(ans == INT_MAX) return -1;

        return ans;
    }
};