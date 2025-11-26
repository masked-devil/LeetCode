class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int i=0;
        for(;i<k;i++){
            pq.push(nums[i]);
        }

        for(;i<nums.size();i++){
            int element=nums[i];
            if(element > pq.top()){
                pq.pop();
                pq.push(element);
            }
        }

        return pq.top();
        
    }
};