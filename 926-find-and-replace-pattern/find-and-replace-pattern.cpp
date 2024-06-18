class Solution {
public:

    void normalize(string& str){
        int map[300]={0};
        int start = 'a';

        for(int i=0;i<str.length();i++){
            char ch=str[i];
            if(map[ch]==0){
                map[ch]=start++;
            }
            str[i]=map[ch];
        }
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {

        vector<string> ans;
        normalize(pattern);
        for(auto word:words){
            string str=word;
            normalize(str);
            if(str==pattern){
                ans.push_back(word);
            }
        }
        return ans;

        
    }
};