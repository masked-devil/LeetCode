class Solution {
public:
    int solveUsingRecursion(int n){
        if(n<=1){
            return n;
        }

        int ans = solveUsingRecursion(n-1) + solveUsingRecursion(n-2);

        return ans;
    }
    int fib(int n) {
        return solveUsingRecursion(n);
    }
};