class Solution {
public:
    int reverse(int x) {
        unsigned int number = abs(x);
        unsigned int reverse=0;
        int max=INT_MAX;
        while(number>0){
            int digit=number%10;
            if(reverse > max/10)return 0;
            reverse=reverse*10+digit;
            
            number/=10;
        }
        // if(reverse>=max)return 0;
        return x>0?reverse:-1*reverse;
    }
};