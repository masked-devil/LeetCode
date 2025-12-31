class Solution {
public:
    int solveUsingRec(string& text1, string& text2, int a, int b){
        if(a>=text1.length() || b>=text2.length()){
            return 0;
        }
        if(text1[a] == text2[b]){
            return 1+solveUsingRec(text1,text2,a+1,b+1);
        }
        else{
            int option1 = solveUsingRec(text1,text2,a+1,b);
            int option2 = solveUsingRec(text1,text2,a,b+1);
            return max(option1, option2);
        }
    }
    int solveUsingMem(string& text1, string& text2, int a, int b, vector<vector<int>>& dp){
        if(a>=text1.length() || b>=text2.length()){
            return 0;
        }

        if(dp[a][b]!=-1){
            return dp[a][b];
        }
        if(text1[a] == text2[b]){
            dp[a][b] = 1+solveUsingMem(text1,text2,a+1,b+1,dp);
        }
        else{
            int option1 = solveUsingMem(text1,text2,a+1,b,dp);
            int option2 = solveUsingMem(text1,text2,a,b+1,dp);
            dp[a][b] = max(option1, option2);
        }

        return dp[a][b];
    }
    int longestCommonSubsequence(string text1, string text2) {
        // return solveUsingRec(text1,text2,0,0);
        vector<vector<int>> dp(text1.length()+1, vector<int>(text2.length()+1,-1));
        return solveUsingMem(text1, text2, 0,0,dp);
    }
};