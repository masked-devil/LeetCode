class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> ans;
        priority_queue<pair<int,int>> pq;

        for(int i=0;i<k;i++){

            pq.push(make_pair(nums[i],i));
        }

        ans.push_back(pq.top().first);

        for(int i=k;i<n;i++){
            pq.push(make_pair(nums[i],i));

            while(!pq.empty() && i-pq.top().second>=k){
                pq.pop();
            }
            ans.push_back(pq.top().first);
        }

        return ans;

    }
};