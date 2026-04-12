class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int locations[1001] = {0};
        for(auto trip:trips){
            int passangers = trip[0];
            if(passangers > capacity) return false;

            int start = trip[1];
            int end = trip[2];

            locations[start]+=passangers;
            locations[end]-=passangers;
        }

        int currPassangers = 0;
        for(int i=0;i<1001;i++){
            currPassangers+=locations[i];
            if(currPassangers > capacity) return false;

        }

        return true;
    }
};