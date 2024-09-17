class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        map<string, int> mp;
        vector<string> ans;
        int start=0;

        for(int i=0;i<=s1.size();i++){
            if(s1[i]==' ' || s1[i]=='\0'){
                string word=s1.substr(start,i-start);
                if(mp.count(word)==1){
                    mp[word]++;

                }
                else{
                    mp[word]=1;
                }
                start=i+1;
            }
        }
        start=0;
        for(int i=0;i<=s2.size();i++){
            if(s2[i]==' ' || s2[i]=='\0'){
                string word=s2.substr(start,i-start);
                if(mp.count(word)!=1){
                    mp[word]=1000;
                }
                else{
                    mp[word]++;
                }
                start=i+1;
            }
        }
        for(auto it:mp){
            if((it.second==1 || it.second==1000)){
                ans.push_back(it.first);
            }
        
        }
        return ans;
        
    }
};