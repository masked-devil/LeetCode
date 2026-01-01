class Solution {
public:
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
    int longestPalindromeSubseq(string s) {
        string r = s;
        reverse(r.begin(), r.end());

        return solveUsingSO2(s,r);
    }
};