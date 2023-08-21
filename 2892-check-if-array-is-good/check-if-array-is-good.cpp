class Solution {
public:
    bool isGood(vector<int>& nums) {
        
        int H[100]={0};
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=nums.size()) return false;
            H[nums[i]-1]++;

        }
        if(H[nums.size()-2]!=2) return false;
        for(int i=0;i<nums.size()-2;i++){
            if(H[i]!=1) return false;
        }
        return true;
    }
};