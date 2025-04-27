class Solution {
public:
    void updateBits(int n, vector<int>& sumOfBits){
        int pos=31;
        while(n && pos>=0){
            if(n&1){
                sumOfBits[pos]++;
            }
            n=n>>1;
            pos--;
        }
    }
    int singleNumber(vector<int>& nums) {
        vector<int> sumOfBits(32,0);
        int ans=0;
        int factor=1;

        for(int x:nums){
            updateBits(x,sumOfBits);
        }



        for(int i=sumOfBits.size()-1;i>=0;i--){
            if(sumOfBits[i]%3==1){
                ans+=factor;
            }
            factor=factor<<1;
        }

        return ans;

    }
};