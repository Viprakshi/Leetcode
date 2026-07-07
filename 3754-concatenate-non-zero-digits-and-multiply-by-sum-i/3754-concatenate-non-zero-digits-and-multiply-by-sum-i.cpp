class Solution {
public:
    long long sumAndMultiply(int n) {
        long long num=0;
        while(n>0){
            if(n%10==0){
                n=n/10;
                
            }
            else{
                 num=(num*10)+(n%10);
                    n=n/10;
            }
           
        }
        long long rev=0;
        long long sum=0;
        while(num>0){
            rev=(rev*10)+(num%10);
            sum+=(num%10);
            num=num/10;
        }
        rev=(rev)*sum;
        return rev;
    }
};