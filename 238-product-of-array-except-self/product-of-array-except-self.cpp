class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefix(n,1);
        vector<int> suffix(n,1);
        vector<int> answer(n,1);
        int product = 1;
        prefix[0]=1;
        suffix[0]=1;
        for(int i=1;i<n;i++){
            product*=nums[i-1];
            prefix[i]=product;
        }
        product=1;
        for(int i=1;i<n;i++){
            product*=nums[n-i];
            suffix[i]=product;

        }
        for(int i=0,j=n-1;i<n;i++,j--){
            answer[i]=prefix[i]*suffix[j];
        }
        return answer;
        
    }
};