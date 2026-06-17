class Solution {
public:
    int func(int i){
        if(i%4==1) return 1;
        if(i%4==2) return i+1;
        if(i%4==3) return 0;
        if(i%4==0) return i;
        return 0;
    }
    int xorOperation(int n, int start) {
        int k=0;
        int x=0;
        while(k<n){
            x=x^(start+(2*k));
            k++;
        }
        return x;
    }
};