class Solution {
public:
    int gcd(int a,int b){

        if(a==0) return b;
        else if(b==0) return a;

        if(a>b) return gcd(a-b,b);
        else return gcd(b-a,a);

    }
    int findGCD(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int GCD=gcd(nums.front(),nums.back());

        return GCD;
        
    }
};