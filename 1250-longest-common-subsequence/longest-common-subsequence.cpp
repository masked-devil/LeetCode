class Solution {
public:
    int solveUsingRec(string& text1, string& text2, int index1, int index2) {
        if (index1 >= text1.length() || index2 >= text2.length()) {
            return 0;
        }
        if (text1[index1] == text2[index2]) {
            return 1 + solveUsingRec(text1, text2, index1 + 1, index2 + 1);
        } else {
            int option1 = solveUsingRec(text1, text2, index1 + 1, index2);
            int option2 = solveUsingRec(text1, text2, index1, index2 + 1);
            return max(option1, option2);
        }
    }
    int solveUsingMem(string& text1, string& text2, int index1, int index2,
                      vector<vector<int>>& dp) {
        if (index1 >= text1.length() || index2 >= text2.length()) {
            return 0;
        }

        if (dp[index1][index2] != -1) {
            return dp[index1][index2];
        }
        if (text1[index1] == text2[index2]) { 
            dp[index1][index2] = 1 + solveUsingMem(text1, text2, index1 + 1, index2 + 1, dp);
        } else {
            int option1 = solveUsingMem(text1, text2, index1 + 1, index2, dp);
            int option2 = solveUsingMem(text1, text2, index1, index2 + 1, dp);
            dp[index1][index2] = max(option1, option2);
        }

        return dp[index1][index2];
    }
    int solveUsingTab(string& text1, string& text2) {
        int m = text1.length();
        int n = text2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {

                if (text1[i] == text2[j]) {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                } else {
                    int option1 = dp[i + 1][j];
                    int option2 = dp[i][j + 1];
                    dp[i][j] = max(option1, option2);
                }
            }
        }

        return dp[0][0];
    }

    int solveUsingSO(string& text1, string& text2) {
        int m = text1.length();
        int n = text2.length();
        vector<int> next(n+1,0);
        vector<int> curr(n+1,0);

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {

                if (text1[i] == text2[j]) {
                    curr[j] = 1 + next[j + 1];
                } else {
                    int option1 = next[j];
                    int option2 = curr[j + 1];
                    curr[j] = max(option1, option2);
                }
            }
            next = curr;
        }

        return curr[0];
    }

    int solveUsingSO2(string& text1, string& text2) {
        int m = text1.length();
        int n = text2.length();
        vector<int> curr(n+1,0);

        for (int i = m - 1; i >= 0; i--) {
            int prevDiag = 0;
            for (int j = n-1; j >= 0; j--) {
                int temp = curr[j];
                if (text1[i] == text2[j]) {
                    curr[j] = 1 + prevDiag;
                } else {
                    int option1 = curr[j];
                    int option2 = curr[j+1];
                    curr[j] = max(option1, option2);
                }
                prevDiag = temp;

            }
        }

        return curr[0];
    }

    int longestCommonSubsequence(string text1, string text2) {
        // return solveUsingRec(text1,text2,0,0);
        // vector<vector<int>> dp(text1.length() + 1,
        //                        vector<int>(text2.length() + 1, -1));
        // return solveUsingMem(text1, text2, 0, 0, dp);

        // return solveUsingTab(text1, text2);

        // return solveUsingSO(text1, text2);
        return solveUsingSO2(text1, text2);
    }
};