class Solution {
public:
    int solveUsingSO(string& text1, string& text2) {
        int n = text1.length();
        int m = text2.length();
        vector<int> next(m+1,0);
        vector<int> curr(m+1,0);

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {

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
    int longestPalindromeSubseq(string s) {
        string r = s;
        reverse(r.begin(), r.end());

        return solveUsingSO(s,r);
    }
};