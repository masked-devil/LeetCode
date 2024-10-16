class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        vector <int> ans(2);
        for(int i=0;i<size;i++){
            for(int j=0; j<size;j++){
                if(nums[i]==target-nums[j] && i!=j){
                    ans[0]=i;
                    ans[1]=j;
                }
            }
        }
        return ans;
    }
};