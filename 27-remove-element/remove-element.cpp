class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0;
        int j=nums.size()-1;
        int count=0;
        if(nums.size()==1){
            return nums[i]==val?0:1;
        }
        while(i<=j){
            while(nums[i]!=val && i<j) {
                i++; count++;
            }
            while(i<=j && nums[j]==val){ j--;}

            if(i<=j)
            {
                swap(nums[i++],nums[j--]);
                count++;
            }

        }
        return count;
        
    }
};