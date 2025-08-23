class Solution {
public:
    int numSquares(int n) {
         vector<int> squares;
         for(int i=1;i*i<=n;i++) squares.push_back(i*i);
         vector<int> dp(n+1,n+1);
         dp[0]=0;
         for(int j=1;j<n+1;j++){
            for(int square:squares){
                if(j-square>=0)
                dp[j]=min(dp[j],1+dp[j-square]);
                else break;
            }
         }
         return dp[n];
    }
};