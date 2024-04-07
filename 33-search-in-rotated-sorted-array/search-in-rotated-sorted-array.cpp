class Solution {
public:
    int PivotIndex(vector<int>& nums){
        int n=nums.size();
        int low=0;
        int high=n-1;
        int mid=low+(high-low)/2;
        

        while(low<=high){
            
            if(low==high){
                return low;
            }

            if(mid+1<n && nums[mid]>nums[mid+1]){
                return mid;
            }
            else if(mid-1>=0 && nums[mid]<nums[mid-1]){
                return mid-1;
            }
            else if(nums[low]>nums[mid]){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
            mid=low+(high-low)/2;
            
        }
        return -1;
    }

    int binarySearch(vector<int>& nums, int low, int high,int target){
        while(low<=high){
            int mid=high+(low-high)/2;

            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return -1;
    }
   



    int search(vector<int>& nums, int target) {
        int pivot=PivotIndex(nums);
        int n=nums.size();
        int ans=-1;
        if(target>=nums[0] && target<=nums[pivot]){
            ans=binarySearch(nums,0,pivot,target);
        }
        else{
            ans=binarySearch(nums,pivot+1,n-1,target);
        }
        return ans;


        
    }
};