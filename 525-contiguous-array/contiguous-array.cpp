class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        vector<int> pre(n);
        unordered_map<int,int> mp;
        int ans = 0;
        mp[0] = -1;
        pre[0] = nums[0]==1?1:-1;
        mp[pre[0]] = 0;
        for(int i=1;i<n;i++){
            pre[i] = pre[i-1];
            pre[i] += (nums[i]==1?1:-1);

            if(mp.find(pre[i]) == mp.end()){
                mp[pre[i]] = i;
            }
            else{
                ans = max(ans, i-mp[pre[i]]);
            }
        }

        return ans;
    }
};