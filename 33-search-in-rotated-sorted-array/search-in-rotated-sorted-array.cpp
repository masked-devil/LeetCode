class Solution {
public:
    int solve(vector<int>& nums, int target, int low, int high){
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;

            if(nums[mid]==target){
                ans=mid;
                break;
            }
            else if(nums[mid]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
    int search(vector<int>& nums, int target) {
        int n=nums.size()-1;
        int pivotIndex=n;
        int ans=-1;

        int low=0;
        int high=n;
        
        while(low<=high){
            int mid=low+(high-low)/2;

            if(mid<n && nums[mid]>nums[mid+1]){
                pivotIndex=mid;
                break;
            }
            else if(nums[mid]<nums[0]){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }

        if(target<nums[0]){
            ans=solve(nums,target, pivotIndex+1,n);
        }
        else{
            ans=solve(nums,target, 0, pivotIndex);
        }

        
        return ans;
    }
};