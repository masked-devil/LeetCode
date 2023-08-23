class Solution {
public:
    bool isPerfectSquare(int num) {

        unsigned int l=1;
        unsigned int h=num;
        long long unsigned int mid=(l+h)/2;
        while(l<=h){
            if(mid*mid==num) return true;
            else if(mid*mid>num) h=mid-1;
            else l=mid+1;
            mid=(l+h)/2;
        }
        return 0;

    }
};