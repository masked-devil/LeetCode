class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length()) return false;

        vector<int> freq1(26,0);
        vector<int> freq2(26,0);

        for(char x:s1){
            freq1[x-'a']++;
        }

        for(int i=0;i<s1.length();i++){
            char x=s2[i];
            freq2[x-'a']++;
        }
        if(freq1==freq2) return true;
        for(int i=s1.length();i<s2.length();i++){
            char next=s2[i];
            char prev=s2[i-s1.length()];
            freq2[next-'a']++;
            freq2[prev-'a']--;
            if(freq1==freq2)return true;
        }

        return false;
    }
};