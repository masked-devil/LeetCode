class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        map<int, pair<int,int>> mp;
        for(auto log:logs){
            int birth = log[0];
            int death = log[1];

            mp[birth].first++;
            mp[death].second++;
        }

        pair<int,int> ans = {0,0};
        vector<pair<int,int>> pre;
        int i=0;

        for(auto x:mp){
            int alive = x.second.first - x.second.second;
            int prevAlive = 0;
            if(i>0) prevAlive = pre[i-1].second;
            int totalAlive = alive + prevAlive;

            if(totalAlive > ans.second){
                ans = {x.first, totalAlive};
            }

            pre.push_back({x.first, totalAlive});
            i++;
        }

        return ans.first;
    }
};