class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> mp;
        set<char> mapped;

        for(int i =0 ;i<s.length();i++){
            char c = s[i];
            if(mp.find(c)==mp.end()){
                if(mapped.contains(t[i])){
                    return false;
                }
                mapped.insert(t[i]);
                mp[c] = t[i];
                s[i]=t[i];
            }
            else{
                s[i]=mp[c];
            }
        }

        return s==t;

    }
};