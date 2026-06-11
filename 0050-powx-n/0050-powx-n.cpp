class Solution {
public:
    double helper(double x, long long n){
        if(n==0) return 1;
        if(n==1) return x;

        if(n%2==0){
            //bro is even 
            return helper(x*x, n/2);
        }
        return x * helper(x,n-1);
    }
    double myPow(double x, int n) {
        long long num=n; 
        if(num<0)
        return 1.0/(helper(x,-num));
        return helper(x,num);
    }
};