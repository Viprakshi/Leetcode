class Solution {
public:
    int cal(vector<vector<int>>& me,vector<vector<int>>& dp,int x, int y){
        //top down
        if(x==0 && y==0 && me[x][y]!=1) return 1;
        if(x<0 || y<0 || me[x][y]==1) return 0;
        if(dp[x][y]!=-1) return dp[x][y];
        int up=cal(me,dp,x,y-1);
        int left=cal(me,dp,x-1,y);
        dp[x][y]=up+left;
        return dp[x][y];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size(),n=obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return cal(obstacleGrid,dp,m-1,n-1);
    }
};