// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int low=0;
        int high=n;
        long long unsigned int mid=(low+high)/2;
        
        while(low<high){
            if(isBadVersion(mid)){
                if(!isBadVersion(mid-1)) break;
                else high=mid-1;
            }
            else{
                low=mid+1;
            }
            mid=(long long unsigned int)low+high;
            mid/=2;
        }
        return mid;

        
    }
};