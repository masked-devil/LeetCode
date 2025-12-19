class Solution {
public:
    int solveUsingMem(int n, vector<int>& dp){
        if(n<=1){
            return n;
        }

        if(dp[n]!=-1){
            return dp[n];
        }

        dp[n] = solveUsingMem(n-1,dp) + solveUsingMem(n-2,dp);

        return dp[n];

    }
    int solveUsingRecursion(int n){
        if(n<=1){
            return n;
        }

        int ans = solveUsingRecursion(n-1) + solveUsingRecursion(n-2);

        return ans;
    }
    int solveUsingTab(int n){
        vector<int> dp(n+1,-1);

        dp[0]=0;
        if(n<1) return dp[n];
        dp[1]=1;

        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }

        return dp[n];
    }
    int solveUsingSO(int n){
        int prev = 0;
        int curr = 1;

        if(n<=1){
            return n;
        }

        int ans;
        for(int i=2;i<=n;i++){
            ans=prev+curr;
            prev=curr;
            curr=ans;
        }

        return ans;
    }
    int fib(int n) {
        // vector<int> dp(n+1,-1);
        // return solveUsingRecursion(n);
        // return solveUsingMem(n,dp);
        // return solveUsingTab(n);
        return solveUsingSO(n);
    }
};