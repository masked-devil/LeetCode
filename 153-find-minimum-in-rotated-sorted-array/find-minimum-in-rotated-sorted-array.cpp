class Solution {
public:

    int findMin(vector<int>& nums) {
        int ans=nums[0];
        int n=nums.size()-1;
        int low=0;
        int high=n;

        while(low<=high){
            int mid=low+(high-low)/2;

            if(mid!=0 && nums[mid]<nums[mid-1]){
                ans=nums[mid];
                break;
            }
            else if(nums[mid]>=nums[0]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }

        return ans;
    }
};