class Solution {
public:
    int cal(vector<vector<int>>& grid,vector<vector<int>>& dp,int x, int y){
        if(x==0 && y==0) return grid[0][0];
        if(x<0 || y<0) return 1e9;
        if(dp[x][y]!=-1) return dp[x][y];
        int up=grid[x][y]+cal(grid, dp, x,y-1);
        int left=grid[x][y]+cal(grid, dp, x-1,y);
        dp[x][y]=min(up,left);
        return dp[x][y];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return cal(grid, dp, m-1, n-1);
    }
};