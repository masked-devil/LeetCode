class Solution {
public:
    int mySqrt(int x) {
        int low=0;
        int high=x;
        int mid=low+(high-low)/2;
        int ans=0;
        if(x<2){
            return x;
        }

        while(low<=high){
            if(x/mid >= mid){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
            mid=low+(high-low)/2;
        }
        return ans;
        
    }
};