class Solution {
public:
    int maximumGood(vector<vector<int>>& statements) {
        int n = statements.size();
        int ans = 0;

        for (int mask = 0; mask < (1<<n); mask++) {

            bool isMaskValid = true;

            for (int i = 0; i < n; i++) {

                if (mask & (1 << i)) {

                    for (int j = 0; j < n; j++) {
                        if (statements[i][j] != 2) {
                            int maskClaim = (mask & (1 << j)) ? 1 : 0;
                            if (statements[i][j] != maskClaim)
                                isMaskValid = false;
                        }
                    }
                }
            }

            if (isMaskValid) {
                ans = max(ans, __builtin_popcount(mask));
            }
        }
        return ans;
    }
};