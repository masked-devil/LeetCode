class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
       vector<long long int> H(k,0);
       long long int ans=0;
        for(int x:arr){
            H[(x%k+k)%k]++;
        }
        
        if(H[0]%2!=0){
            return false;;
        }
        for(int i=1;i<=(k-1)/2;i++){
            int j=k-i;
            if(H[i]!=H[j]){
                return false;
            }
            
        }
        return true;

        
    }
};