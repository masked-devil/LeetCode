class Solution {
public:
    bool isNumber(char c){
        if(c>='0' && c<='9') return true;

        return false;
    }
    bool areNumbersAscending(string s) {
        int number=-1;
        bool answer=true;

        int i=0;
        int n=s.length();

        while(i<n){
            int temp=0;
            while(i<n && !isNumber(s[i])){
                i++;
            }

            while(i<n && isNumber(s[i])){
                temp=temp*10+(s[i]-'0');
                i++;
            }
            if(i==n && !isNumber(s[i-1])){
                break;
            }
            if(temp<=number){
                answer=false;
                break;
            }
            number=temp;
        }

        return answer;
    }
};