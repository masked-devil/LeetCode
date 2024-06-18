class Solution {
public:


    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int totalG=0;
        int totalP=0;
        int totalM=0;

        int travelG=0;
        int travelP=0;
        int travelM=0;
        int travelSum=0;

        for(int i=0;i<garbage.size();i++){
            int G=0;
            int P=0;
            int M=0;

            for(int j=0;j<garbage[i].length();j++){
                if(garbage[i][j]=='G'){
                    G++;
                }
                else if(garbage[i][j]=='P'){
                    P++;
                }
                else{
                    M++;
                }
            }
            totalG+=G;
            totalP+=P;
            totalM+=M;

            

            if(G>0){
                travelG=travelSum;
            }
            if(P>0){
                travelP=travelSum;
            }
            if(M>0){
                travelM=travelSum;
            }
            if(i<travel.size()){travelSum+=travel[i];}
        }
        int cost=totalG+totalP+totalM+travelG+travelP+travelM;
        return cost;
    }
};