class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pre(n,0);
        unordered_map<int, int> mp;
        int ans=0;
        mp[0]=1;

        for(int i=0;i<n;i++){
            if(i>0) pre[i]+=pre[i-1];

            if(nums[i]%2 == 1){
                pre[i]++;
            }


            if(mp.find(pre[i] - k) != mp.end()){
                ans+= mp[pre[i]-k];
            }

            mp[pre[i]]++;
        }
        return ans;
    }
};