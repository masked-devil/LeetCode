class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int fuelTank=0;
        int deficit=0;
        int start=0;

        for(int i=0;i<gas.size();i++){
            fuelTank+=gas[i]-cost[i];

            if(fuelTank<0){
                deficit+=abs(fuelTank);
                fuelTank=0;
                start=i+1;
            }
        }

        if(fuelTank<abs(deficit)){
            return -1;
        }
        return start;



    }
};