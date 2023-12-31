class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low,mid,high;
        low=0;
        high=nums.size()-1;
        
        if(nums[0]>=target ) return 0;
        
        while(low<high){
            mid=(low+high)/2;
            if(nums[mid]==target) return mid;
            if(nums[mid]>target && nums[mid-1]<target) return mid;
            if(nums[mid]>target) high=mid-1;
            if(nums[mid]<target && nums[mid+1]>=target)return mid+1;
            if(nums[mid]<target) low=mid+1;
        }

        
        return nums.size();
        
    }
};