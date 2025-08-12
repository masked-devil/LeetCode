class Solution {
public:
    bool predicate(vector<int>& piles, int mid, int h){
        long long hours=0;

        for(int x:piles){
            hours+=(ceil(1.0*x/mid));
        }

        return hours>h?false:true;

    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int high=*max_element(piles.begin(),piles.end());
        int low=1;
        int ans=high;

        while(low<=high){
            int mid=low+(high-low)/2;

            if(predicate(piles, mid, h)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }

        return ans;
    }
};