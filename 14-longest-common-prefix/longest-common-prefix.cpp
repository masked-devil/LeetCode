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
    void addWord(TrieNode* root, string word){
        if(word.length()==0){
            root->isTerminal = true;
            return;
        }

        char ch = word[0];
        TrieNode* child;

        if((root->children).count(ch)==0){
            child = new TrieNode(ch);
            (root->children)[ch]=child;
        }
        else{
            child = (root->children)[ch];
        }
        addWord(child, word.substr(1));
    }
    string longestCommonPrefix(vector<string>& strs) {
        TrieNode* root = new TrieNode('-');

        for(auto s:strs){
            addWord(root,s);
        }

        string ans = "";

        TrieNode* curr = root;

        while((curr->children).size()==1 && curr->isTerminal==false){
            curr = (*((curr ->children).begin())).second;

            ans.push_back(curr->ch);
        }

        return ans;
    }
};