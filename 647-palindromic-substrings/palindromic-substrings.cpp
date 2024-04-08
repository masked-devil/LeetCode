class Solution {
public:
    int countSubstrings(string s) {
        int n=s.length();
        int totalCount=0;
        int index=0;
        for(;index<n;index++){
            int i=index;
            int j=index;
            while(i>=0 && j<n){
                if(s[i]==s[j]){
                  totalCount++;
                    i--;
                    j++;
                }
                else{
                    break;
                }
            }
            i=index;
            j=index+1;
            while(i>=0 && j<n){
                if(s[i]==s[j]){
                  totalCount++;
                    i--;
                    j++;
                }
                else{
                    break;
                }

            }
        }
        return totalCount;
        
    }
};