class Solution {
public:
    vector<int> deltarow={-1,0,1,0};
    vector<int> deltacol={0,1,0,-1};
    void dfs(int x, int y, vector<vector<int>>& vis, vector<vector<int>>& grid){
        vis[x][y]=1;
        
        for(int i=0;i<4;i++){
            int nr=x+deltarow[i];
            int nc=y+deltacol[i];
            if(nr<0 || nc<0 || nr>=grid.size() || nc>=grid[0].size() || grid[nr][nc]==0) continue;
            else if(!vis[nr][nc]){
                dfs(nr, nc, vis, grid);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
       //first check for boundaries 
       int m=grid.size();
       int n=grid[0].size();
       int count=0;
       vector<vector<int>> vis(m, vector<int>(n,0)); 

       for(int i=0;i<m;i++){
        if(!vis[i][0] && grid[i][0]==1){
            dfs(i,0,vis,grid);
        }
       }
       for(int i=0;i<n;i++){
        if(!vis[m-1][i] && grid[m-1][i]==1){
            dfs(m-1,i,vis,grid);
        }
       }
       for(int i=0;i<m;i++){
        if(!vis[i][n-1] && grid[i][n-1]==1){
            dfs(i,n-1,vis,grid);
        }
       }
       for(int i=0;i<n;i++){
        if(!vis[0][i] && grid[0][i]==1){
            dfs(0,i,vis,grid);
        }
       }

       for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1 && vis[i][j]==0)
            count++;
        }
       }
       return count;
    }
};