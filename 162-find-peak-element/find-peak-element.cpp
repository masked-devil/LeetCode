class Solution {
public:
    bool isPeakElement(int& index, vector<int>& nums){
        if(index==0){
            return nums[index]>nums[index+1];
        }
        else if(index==nums.size()-1){
            return nums[index]>nums[index-1];
        }
        else{
            return (nums[index]>nums[index-1] && nums[index]>nums[index+1]);
        }
    }
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        int ans=-1;

        if(n==1){
            return 0;
        }

        while(low<=high){
            int mid=low+(high-low)/2;

            if(isPeakElement(mid, nums)){
                ans=mid;
                break;
            }
            else if(mid==0 || nums[mid]>nums[mid-1]){
                low=mid+1;
            }
            else if(mid==n-1 || nums[mid]>nums[mid+1]){
                high=mid-1;
            }
            else{
                low++;
            }
        }

        return ans;
    }
};