class Solution {
public:
    bool checkStr(string str){
        for(int i=0;i<str.length();i++){
            if(str[i]!=str[0]){
                return false;
            }

        }
        return true;

    }
    string removeDuplicates(string s, int k) {
        int i=0;

        while(i+k-1<s.length()){
            if(s.length()<k){
                return s;
            }   
            if(checkStr(s.substr(i,k))){
                s.erase(i,k);
                i=max(0,i-k+1);

            }
            else{
                i++;
            }
        }
        return s;
    }
};