class Solution {
public:
    int reverse(int x) {
        bool isNegative=x<0?true:false;
        int rev=0;
        while(x!=0){
            int temp= x%10;
            if(isNegative){
                temp=-1*temp;
            }
            x=x/10;
            if(rev>INT_MAX/10){
                return 0;
            }
            rev= rev*10+temp;
        }
        return isNegative?-rev:rev;
    }
};