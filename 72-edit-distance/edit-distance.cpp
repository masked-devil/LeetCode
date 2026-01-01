class Solution {
public:
    int solveUsingRec(string& word1, string& word2, int a, int b) {
        if (a == word1.length()) {
            return word2.length() - b;
        }
        if (b == word2.length()) {
            return word1.length() - a;
        }

        if (word1[a] == word2[b]) {
            return solveUsingRec(word1, word2, a + 1, b + 1);
        } else {
            int repl = 1 + solveUsingRec(word1, word2, a + 1, b + 1);
            int del = 1 + solveUsingRec(word1, word2, a + 1, b);
            int ins = 1 + solveUsingRec(word1, word2, a, b + 1);

            return min({repl, del, ins});
        }
    }
    int solveUsingMem(string& word1, string& word2, int a, int b,
                      vector<vector<int>>& dp) {
        if (a == word1.length()) {
            return word2.length() - b;
        }
        if (b == word2.length()) {
            return word1.length() - a;
        }
        if (dp[a][b] != -1) {
            return dp[a][b];
        }
        if (word1[a] == word2[b]) {
            dp[a][b] = solveUsingMem(word1, word2, a + 1, b + 1, dp);
        } else {
            int repl = 1 + solveUsingMem(word1, word2, a + 1, b + 1, dp);
            int del = 1 + solveUsingMem(word1, word2, a + 1, b, dp);
            int ins = 1 + solveUsingMem(word1, word2, a, b + 1, dp);

            dp[a][b] = min({repl, del, ins});
        }

        return dp[a][b];
    }

    int solveUsingTab(string& word1, string& word2) {
        vector<vector<int>> dp(word1.length() + 1,
                               vector<int>(word2.length() + 1, -1));
        int m = word1.length();
        int n = word2.length();
        for(int j = 0; j<=n;j++){
            dp[m][j] = n-j;
        }
        for(int i = 0; i<=m;i++){
            dp[i][n] = m-i;
        }
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (word1[i] == word2[j]) {
                    dp[i][j] = dp[i + 1][j + 1];
                } else {
                    int repl = 1 + dp[i + 1][j + 1];
                    int del = 1 + dp[i + 1][j];
                    int ins = 1 + dp[i][j + 1];

                    dp[i][j] = min({repl, del, ins});
                }
            }
        }

        return dp[0][0];
    }
    int minDistance(string word1, string word2) {
        // return solveUsingRec(word1,word2,0,0);
        vector<vector<int>> dp(word1.length() + 1,
                               vector<int>(word2.length() + 1, -1));
        // return solveUsingMem(word1, word2, 0, 0, dp);
        return solveUsingTab(word1, word2);
    }
};