class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int sum=0;
        // vector<int> diff(n);
        queue<pair<int,int>> q;

        for(int i=0;i<n;i++){
            pair<int,int> diff=make_pair(gas[i]-cost[i],i);
            sum+=diff.first;
            q.push(diff);
        }
        if(sum<0){
            return -1;
        }
        sum=0;
        int k=n;
        while(k){
            pair<int,int> num=q.front();
            
            sum+=num.first;
            if(sum<0){
                sum=0;
                k=n;
            }
            else{
                k--;
            }
            q.pop();
            q.push(num);
        }
        return q.front().second;





    }
};