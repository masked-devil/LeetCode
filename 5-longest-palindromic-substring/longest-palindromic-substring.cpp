class Solution {
public:
    string getPalindrome(string& s, int l, int r){
        while(l>=0 &&  r<s.length() && s[l]==s[r]){
            l--;
            r++;
        }
        return s.substr(l+1, r-l-1);
    }
    string longestPalindrome(string s) {
        string ans = s.substr(0,1);

        for(int i=0;i<s.length()-1;i++){
            string odd = getPalindrome(s, i, i);
            if(odd.length() > ans.length()) ans= odd;
            string even = getPalindrome(s, i, i+1);
            if(even.length() > ans.length()) ans= even;
        }

        return ans;
    }
};