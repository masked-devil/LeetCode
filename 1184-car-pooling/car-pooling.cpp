class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int, int> mp;
        for(auto trip:trips){
            int passangers = trip[0];
            if(passangers > capacity) return false;

            int start = trip[1];
            int end = trip[2];

            mp[start]+=passangers;
            mp[end]-=passangers;
        }

        int currPassangers = 0;
        for(auto x:mp){
            currPassangers += x.second;
            if(currPassangers > capacity) return false;
        }

        return true;
    }
};