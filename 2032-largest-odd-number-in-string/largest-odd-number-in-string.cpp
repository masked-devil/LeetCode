class Solution {
public:
    string largestOddNumber(string num) {
        int index=num.length()-1;
        int number=num[index]-'0';
        while(index >=0 && number%2==0){
            index--;
            if(index>=0) number=num[index]-'0';
        }
        if(index>=0){
            return num.substr(0,index+1);
        }
        return "";

    }
};