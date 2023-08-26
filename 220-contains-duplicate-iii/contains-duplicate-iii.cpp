class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        for(unsigned int i=0;i<nums.size()-1;i++){
            for(unsigned int j=i+1;j<=i+indexDiff && j<nums.size();j++){
                if(abs(nums[i]-nums[j])<=valueDiff) return true;
            }
        }
        return false;
    }
};