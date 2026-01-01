class Solution {
public:
    int solveUsingRec(string& word1, string& word2, int index1, int index2) {
        if (index1 == word1.length()) {
            return word2.length() - index2;
        }
        if (index2 == word2.length()) {
            return word1.length() - index1;
        }

        if (word1[index1] == word2[index2]) {
            return solveUsingRec(word1, word2, index1 + 1, index2 + 1);
        } else {
            int repl = 1 + solveUsingRec(word1, word2, index1 + 1, index2 + 1);
            int del = 1 + solveUsingRec(word1, word2, index1 + 1, index2);
            int ins = 1 + solveUsingRec(word1, word2, index1, index2 + 1);

            return min({repl, del, ins});
        }
    }
    int solveUsingMem(string& word1, string& word2, int index1, int index2,
                      vector<vector<int>>& dp) {
        if (index1 == word1.length()) {
            return word2.length() - index2;
        }
        if (index2 == word2.length()) {
            return word1.length() - index1;
        }
        if (dp[index1][index2] != -1) {
            return dp[index1][index2];
        }
        if (word1[index1] == word2[index2]) {
            dp[index1][index2] = solveUsingMem(word1, word2, index1 + 1, index2 + 1, dp);
        } else {
            int repl = 1 + solveUsingMem(word1, word2, index1 + 1, index2 + 1, dp);
            int del = 1 + solveUsingMem(word1, word2, index1 + 1, index2, dp);
            int ins = 1 + solveUsingMem(word1, word2, index1, index2 + 1, dp);

            dp[index1][index2] = min({repl, del, ins});
        }

        return dp[index1][index2];
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
    void printDp(vector<int>& curr){
        for (auto n:curr){
            cout<<n<<" ";
        }
        cout<<endl;
    }
    int solveUsingSO(string& word1, string& word2) {
        vector<int> next(word2.length() + 1, 0);
        vector<int> curr(word2.length() + 1, 1);
        int m = word1.length();
        int n = word2.length();
        for (int j = 0; j <= n; j++) {
            next[j] = n - j;
        }
        
        for (int i = m - 1; i >= 0; i--) {
            curr[n] = m-i;
            for (int j = n - 1; j >= 0; j--) {
                if (word1[i] == word2[j]) {
                    curr[j] = next[j + 1];
                } else {
                    int repl = 1 + next[j + 1];
                    int del = 1 + next[j];
                    int ins = 1 + curr[j + 1];

                    curr[j] = min({repl, del, ins});
                }
            }
            next = curr;
        }

        return next[0];
    }
    int minDistance(string word1, string word2) {
        // return solveUsingRec(word1,word2,0,0);
        // vector<vector<int>> dp(word1.length() ,
        //                        vector<int>(word2.length(), -1));
        // return solveUsingMem(word1, word2, 0, 0, dp);
        // return solveUsingTab(word1, word2);
        return solveUsingSO(word1, word2);
    }
};