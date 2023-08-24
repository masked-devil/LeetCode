class Solution {
public:
    double myPow(double x, int n) {

        if(n==0) return 1;
        if(n==1) return x;
        if(n==-1) return 1/x;
        if(x==0 || x==1) return x;
        if(n==INT_MIN) {
            return myPow(x*x,n/2);
        }
        
        double i=-1;
        if(n<0) return 1/myPow(x,n*i);
        if(x<0){
            if(n%2==0) return myPow(i*x,n);
            else return -1*myPow(i*x,n);
        }
        if(n%2==0) return myPow(x*x,n/2);
        else return x*myPow(x*x,(n-1)/2);
        
        
        
    }
};