class Solution {
public:
    int mySqrt(int x) {
        unsigned long long int l=1;
        unsigned long long int h=x;
        unsigned long long int mid=(l+h)/2;
        if(x==0)return 0;
        int ans=1;

        while(l<=h){
            if(mid*mid==x) return mid;
            else if(mid*mid>x) {h=mid-1;}
            else {ans=mid;l=mid+1;}
            mid=(l+h)/2;
        }
        return ans;
        
    }
};