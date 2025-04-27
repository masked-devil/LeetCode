class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorVal=0;
        int set1=0;
        int set2=0;
        vector<int> ans(2);
        for(int x:nums){
            xorVal=xorVal^x;
        }

        int pos=0;
        int temp=xorVal;

        while((temp&1) == 0){
            pos++;
            temp=temp>>1;
        }

        int mask=1<<pos;;

        for(int x:nums){
            if(x&mask){
                set1=set1^x;
            }
            else{
                set2=set2^x;
            }
        }

        ans[0]=set1;
        ans[1]=set2;

        return ans;


    }
};