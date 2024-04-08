class Solution {
public:
    string removeDuplicates(string s) {
        string ans="";
        ans.push_back(s[0]);
        int i=1;
        while(i<s.length()){
            if(ans.length()>0 && s[i]==ans.back()){
                ans.pop_back();
            }
            else{
                ans.push_back(s[i]);
            }
            i++;

        }
        return ans;
        
    }
};