class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;
        int mid;
        vector<int> result(2);
        
        result[0]=-1;
        result[1]=-1;


        while(low<=high){
            mid=(low+high)/2;

            if(nums[mid]==target){
                if(mid!=0 && nums[mid-1]!=target) {result[0]=mid;break;}
                else if(mid==0) {result[0]=0; break;}
                else high=mid-1;
            }
            else if(nums[mid]>target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        if(result[0]==-1) return result;
        else low=result[0];
        high=nums.size()-1;
        while(low<=high){
            mid=(low+high)/2;

            if(nums[mid]==target){
                if(mid!=nums.size()-1 && nums[mid+1]!=target) {result[1]=mid;break;}
                else if(mid==nums.size()-1) {result[1]=nums.size()-1; break;}
                else low=mid+1;
            }
            else if(nums[mid]>target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return result;
    }
};