class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        if(k==0){
            return;
        }
        vector<int> temp;
        for(int i=n-k;i<n;i++){
            temp.push_back(nums[i]);
        }
        int i=n-1;
        for(;i-k>=0;i--){
            nums[i]=nums[i-k];
        }
        for(;i>=0;i--){
            nums[i]=temp[i];
        }
        
    }
};