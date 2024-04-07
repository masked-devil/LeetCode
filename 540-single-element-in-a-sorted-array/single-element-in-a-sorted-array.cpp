class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low=0;
        int high=nums.size()-1;

        while(low<=high){
            int mid=low+(high-low)/2;

            if(low==high){
                return nums[high];
            }
            if(mid&1){
                if(nums[mid]==nums[mid-1]){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
            else{
                if(mid+1<nums.size() && nums[mid]==nums[mid+1]){
                    low=mid+2;
                }
                else{
                    high=mid;
                }
            }
        }
        return -1;
        
    }
};