class Solution {
public:
    int search(vector<int>& nums, int target) {
        int ans=-1;
        auto it=lower_bound(nums.begin(),nums.end(),target);
        if(it!=nums.end() && target==*(it)) ans=it-nums.begin();

        return ans;
    }
};