class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(nums[0]==sum){
            return 0;
        }
        // else if(nums[n-1]==sum && sum!=0){
        //     return n-1;
        // }
        else{
            int i=0;
            int halfsum=0;
            while(i<n-1){
                halfsum+=nums[i++];
                if(halfsum*2+nums[i]==sum){
                    return i;
                }


            }
            return -1;
        }
        
    }
};