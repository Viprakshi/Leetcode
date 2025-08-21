class Solution {
public:
    int climbStairs(int n) {
        if(n<=1) return 1;
        int curr1=1;
        int curr2=1;
        for(int i=2;i<=n;i++){
            int ans=curr1+curr2;
            curr1=curr2;
            curr2=ans;
        }
        return curr2;
    }
};