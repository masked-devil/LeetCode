class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        vector<int> powers;
        unordered_map<int,int> mp;
        int MOD=1e9+7;
        long long int answer=0;
        int num=1;

        for(int i=0;i<22;i++){
            powers.push_back(num);
            num=num<<1;
        }

        for(int x:deliciousness){
            mp[x]++;
        }

        for(auto x:mp){
            int num=x.first;
            for(int power:powers){
                int comp=power-num;

                if(comp>=0 && mp.find(comp)!=mp.end()){
                    int freq=mp[comp];
                    if(comp==num){
                        answer=answer+(1ll*freq*(freq-1))/2;
                    }
                    else if(comp>num){
                        answer+=1ll*freq*x.second;
                    }
                    answer=answer%MOD;
                }
            }
        }
        return answer%MOD;
    }
};