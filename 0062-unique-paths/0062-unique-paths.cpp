class Solution {
public:
    int cal(int x, int y, vector<vector<int>>& dp){
        if(x==0 && y==0) return 1;
        if(x<0 || y<0) return 0;
        if(dp[x][y]!=-1) return dp[x][y];
        int up=cal(x,y-1,dp);
        int down=cal(x-1,y,dp);
        dp[x][y]=up+down;
        return dp[x][y];
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return cal(m-1,n-1,dp);
    }
};