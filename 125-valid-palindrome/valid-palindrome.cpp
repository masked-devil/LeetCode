class Solution {
public:
    bool isPalindrome(string s) {
        for(int i=0;i<s.length();i++){
            if(s[i]>=65 && s[i]<=90){
                s[i]=s[i]-'A'+'a';
            }
            else if((s[i]>=97 && s[i]<=122) || (s[i]>=48 && s[i]<=57)){
                continue;
            }
            else{
                s.erase(i,1);
                i--;
            }
            
        }
        int i=0;
        int j=s.length()-1;

        while(i<=j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;


        
    }
};