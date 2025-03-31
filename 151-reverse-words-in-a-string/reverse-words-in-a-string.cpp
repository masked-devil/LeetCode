class Solution {
public:
    string reverseWords(string s) {
        vector<string> v;
        int i=0;
        int start=0;
        string result="";
        while(i<s.length()){
            while(i<s.length() && s[i]==' '){
                i++;
            }
            start=i;
            while(i<s.length() && s[i]!=' '){
                i++;
            }
            if(start<s.length()){
                v.push_back(s.substr(start, i-start));
            }
        }
        for(int i=v.size()-1;i>=0;i--){
            result = result + v[i];
            if(i!=0) result.push_back(' ');
        }

        return result;
    }
};