class Solution {
public:
    int climbStairs(int n) {

        if(n==1 || n==2) return n;

        vector<int> stair(n+1,0);
        stair[1]=1;
        stair[2]=2;

        for(int i=3;i<=n;i++){
            stair[i]=stair[i-1]+stair[i-2];
        }      
        return stair[n];
    }
};