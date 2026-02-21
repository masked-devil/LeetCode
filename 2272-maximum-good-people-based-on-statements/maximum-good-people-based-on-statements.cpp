class Solution {
public:
    int maximumGood(vector<vector<int>>& statements) {
        int ans = 0;
        int n = statements.size();
        for(int mask = 1;mask<(1<<n);mask++){
            bool isMaskValid = true;
            for(int i=0;i<n;i++){
                if(mask & (1<<i)){
                    //this assumed to be truth
                    //his statement should match with mask
                    for(int j=0;j<n;j++){
                        int statement=statements[i][j];
                        if(statement!=2){
                            bool maskVal = (mask & (1<<j));
                            bool claimedVal = statement;

                            if(maskVal!=claimedVal){
                                isMaskValid=false;
                            }
                        }
                    }
                }

            }

            if(isMaskValid){
                ans = max(ans,__builtin_popcount(mask));
            }
        }


        return ans;
    }
};