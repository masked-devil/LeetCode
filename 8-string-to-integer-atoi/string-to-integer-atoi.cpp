class Solution {
public:
    bool isSign(char c){
        if(c=='+' || c=='-') return true;

        return false;
    }
    bool isNumber(char c){
        if(c>='0' && c<='9') return true;

        return false;
    }
    int myAtoi(string s) {
        int n=s.length();
        long long int answer=0;
        long long int limit=-1ll*INT_MIN;
        int index=0;
        int startIndex=0;
        bool isPositive=true;


        while(index<n && s[index]==' '){
            index++;
        }

        if(index<n && isSign(s[index])){
            if(s[index]=='-'){
                isPositive=false;
            }
            index++;
        }

        startIndex=index;

        while(index<n && isNumber(s[index])){
            index++;
        }

        
        
        while(startIndex<index && answer<limit){
            int number=s[startIndex]-'0';
            answer=answer*10+number;
            startIndex++;
        }

        if(answer>=limit){
            if(isPositive){
                return INT_MAX;
            }
            else{
                return INT_MIN;
            }
        }
        if(!isPositive){
            answer=-1ll*answer;
        }
        return answer;


    }
};