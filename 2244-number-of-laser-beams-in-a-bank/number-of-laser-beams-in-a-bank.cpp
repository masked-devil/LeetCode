class Solution {
public:

    int countDevices(string row){
        int count=0;
        for(auto ch:row){
            if(ch=='1'){
                count++;
            }
        }
        return count;
    }
    int numberOfBeams(vector<string>& bank) {
        int lastRow=0;
        int beam=0;

        for(int i=0;i<bank.size();i++){
            int count = countDevices(bank[i]);

            beam+=lastRow*count;
            if(count>0){
                lastRow=count;
            }
        }
        return beam;
        
    }
};