class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int ExpectedSum=((n)*(n+1))/2;
        int ActualSum=0;

        for(int i=0;i<n;i++){
            ActualSum+=nums[i];
        }
        int MissingNumber=ExpectedSum-ActualSum;
        return MissingNumber;
        
    }
};