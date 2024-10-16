class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0;
        int high=nums.size()-1;
        int index=0;

        while(index<=high){
            if(nums[index]==0){
                swap(nums[low],nums[index]);
                low++;
                index++;

            }
            else if(nums[index]==1){
                index++;
            }
            else if(nums[index]==2){
                swap(nums[high],nums[index]);
                high--;

                
            }
        }
    }
};