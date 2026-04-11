class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int popDiff[101] = {0};

        for(auto log:logs){
            int birth = log[0];
            int death = log[1];

            popDiff[birth - 1950]++;
            popDiff[death - 1950]--;
        }
        int pop = 0;
        int maxPop = INT_MIN;
        int year = -1;

        for(int i=0;i<101;i++){
            int x = popDiff[i];
            pop+=x;
            if(pop>maxPop){
                maxPop = pop;
                year = i+1950;
            }
        }

        return year;
    }
};