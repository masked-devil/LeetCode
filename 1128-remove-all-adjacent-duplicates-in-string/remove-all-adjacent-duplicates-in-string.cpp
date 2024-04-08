class Solution {
public:
    string removeDuplicates(string s) {
        int i=0;
        int j=1;
        while(j<s.length()){
            if(s[i]==s[j]){
                s.erase(i,2);
                if(i>0){
                    i--;
                    j--;
                }
            }
            else{
                i++;
                j++;
            }
        }
        return s;
        
    }
};