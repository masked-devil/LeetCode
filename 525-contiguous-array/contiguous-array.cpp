class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp;
        int ans = 0;
        mp[0] = -1;
        int pre = nums[0]==1?1:-1;
        mp[pre] = 0;
        for(int i=1;i<n;i++){
            pre = pre;
            pre += (nums[i]==1?1:-1);

            if(mp.find(pre) == mp.end()){
                mp[pre] = i;
            }
            else{
                ans = max(ans, i-mp[pre]);
            }
        }

        return ans;
    }
};