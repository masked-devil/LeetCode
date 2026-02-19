class Solution {
public:
    void solve(vector<string>& ans, int n, string& s) {
        if (s.length() == n) {
            ans.push_back(s);
            return;
        }

        //
        s.push_back('1');
        solve(ans, n, s);
        s.pop_back();
        if ((s.length() > 0 && s.back() != '0') || s.length()==0) {
            s.push_back('0');
            solve(ans, n, s);
            s.pop_back();
        }
    }
    vector<string> validStrings(int n) {
        vector<string> ans;
        string s = "";
        solve(ans, n, s);
        return ans;
    }
};