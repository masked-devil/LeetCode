class Solution {
public:
    int solveTab(vector<int>& coins, int amount ){
        vector<int> dp(amount+1, -1);
        dp[0]=0;

        int mini = INT_MAX;
        for(int i=1;i<=amount;i++){
            int mini = INT_MAX;
            for(auto coin:coins){
                if(i-coin >= 0){
                    int dpAns = dp [i-coin];
                    if(dpAns !=INT_MAX) dpAns++;
                    mini = min(dpAns,mini);
                }
            }
            dp[i]=mini;
        }

        return dp[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        int ans = solveTab(coins, amount);
        if(ans==INT_MAX) return -1;

        return ans;
    }
};