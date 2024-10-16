class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size= nums.size();
        int sum= (size*(size+1))/2;
        int sum2= 0;
        for(int i=0; i<size; i++){
            sum2+= nums[i];
        }
        return sum-sum2;
    }
};