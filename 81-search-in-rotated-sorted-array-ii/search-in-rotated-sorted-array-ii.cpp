class Solution {
public:

    bool search(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;

        while(low<=high){
            int mid=low+(high-low)/2;

            if(nums[mid]==target){
                return true;
            }
            //left is sorted
            else if(nums[mid]>nums[low]){
                //target in sorted
                if(target>=nums[low] && target<nums[mid]){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            //right is sorted
            else if(nums[mid]<nums[low]){
                //target in sorted
                if(target>nums[mid] && target<=nums[high]){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
            else{
                //num[mid]==nums[low], can't decide sorted part, skip duplicate
                low++;
            }
        }
        return false;
        
    }
};