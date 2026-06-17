class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==divisor) return 1;
        if(divisor==1) return dividend;
        if(dividend==INT_MIN && divisor==-1) return INT_MAX;

        int sign=true;
        if(dividend<=0 && divisor>0) sign=false;
        if(dividend>=0 && divisor<0) sign=false;

        long long n=(dividend), d=(divisor);
        n=abs(n), d=abs(d);
        long long sum=0, x=0;
        while(sum+d<=n){
            x++;
            sum+=d;
        }

        if(x>INT_MAX && sign==false) return INT_MIN;
        if(x<INT_MIN && sign==false) return INT_MAX;

        if(sign==false) return x*-1;
        return x;  

    }
};