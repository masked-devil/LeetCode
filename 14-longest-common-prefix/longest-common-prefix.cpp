class TrieNode{
public:
    char ch;
    bool isTerminal;
    unordered_map<char, TrieNode*> children;

    TrieNode(char ch){
        this->ch=ch;
        isTerminal=false;
    }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0) return "";
        string prefix = strs[0];

        for (int i=1;i<strs.size();i++){
            string word=strs[i];
            while(word.find(prefix)!=0){
                prefix.pop_back();
                if(prefix.empty()){
                    return "";
                }
            }
        }

        return prefix;
    }
};