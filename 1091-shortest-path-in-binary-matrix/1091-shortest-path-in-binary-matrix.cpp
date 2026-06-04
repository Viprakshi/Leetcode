class Solution {
public:
    void bfs(int x,int y,int d,vector<vector<int>>& vis,vector<vector<int>>& grid,queue<pair<pair<int,int>, int>>& q){
        vis[x][y]=1;
       vector<int> dx={-1,-1,-1,0,0,1,1,1};
       vector<int> dy={-1,0,1,-1,1,-1,0,1};
       for(int i=0;i<8;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];

        if(nx<0 || ny<0 || nx>=grid.size() || ny>=grid[0].size() || grid[nx][ny]==1) continue;
        if(!vis[nx][ny]){
            q.push({{nx,ny},d+1});
        }
       }
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        queue<pair<pair<int,int>, int>> q;
   
        if(grid[0][0]==1 || grid[m-1][n-1]==1) return -1;
        q.push({{0,0}, 0});
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) vis[i][j]=1;
            }
        }
        while(!q.empty()){
            int x=q.front().first.first;
            int y=q.front().first.second;
            int d=q.front().second;
            if(x==m-1 && y==n-1)
        return d+1;
            q.pop();
            if(!vis[x][y]){
                bfs(x,y,d,vis,grid,q);
            }
            
        }
    return -1;
    }
};