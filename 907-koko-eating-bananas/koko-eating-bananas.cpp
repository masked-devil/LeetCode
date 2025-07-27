class Solution {
public:
    bool predicate(vector<int>& piles, long long k,int h){
        long long hours=0;

        for(auto x:piles){
            if(x%k==0){
                hours+=(x/k);
            }
            else{
                hours+=(x/k+1);
            }
            if(hours>h) return false;
        }
        if(hours>h) return false;

        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=*(max_element(piles.begin(),piles.end()));
        int ans=high;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(predicate(piles,mid,h)){
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