class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& vis, vector<vector<char>>& grid){
        vis[i][j]=1;
        vector<int> deltarow={-1,0,1,0};
        vector<int> deltacol={0,1,0,-1};
        for(int x=0;x<4;x++){
            int nr=i+deltarow[x];
            int nc=j+deltacol[x];
            if(nr<0 || nc<0 || nr>=grid.size() || nc>=grid[0].size()) continue;
            else if(grid[nr][nc]=='1' && vis[nr][nc]==0){
                dfs(nr,nc,vis,grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n,0));
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    ans++;
                    dfs(i, j, vis, grid);
                }
            }
        }
        return ans;
    }
};