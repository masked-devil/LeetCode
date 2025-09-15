class Solution {
public:
string minWindow(const string &s, const string &t) {
    if (s.empty() || t.empty()) return "";

    vector<int> need(256, 0);
    for (unsigned char c : t) need[c]++;

    int required = 0;
    for (int x : need) if (x > 0) required++;

    vector<int> window(256, 0);
    int formed = 0;           
    int l = 0, r = 0;         
    int bestLen = INT_MAX;
    int bestL = 0;

    while (r < (int)s.size()) {
        unsigned char c = s[r];
        window[c]++;

        if (need[c] > 0 && window[c] == need[c]) formed++;

        while (l <= r && formed == required) {
            
            if (r - l + 1 < bestLen) {
                bestLen = r - l + 1;
                bestL = l;
            }

            unsigned char lc = s[l];
            window[lc]--;
            if (need[lc] > 0 && window[lc] < need[lc]) {
                formed--;
            }
            l++;
        }

        r++;
    }

    return bestLen == INT_MAX ? "" : s.substr(bestL, bestLen);
}

};