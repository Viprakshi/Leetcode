class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        int count=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++){
                if(grid[i][j]==2)
                    q.push({{i,j},count});
            }
        }
        vector<vector<int>> vis(m, vector<int> (n,0));
        while(!q.empty()){
            int x=q.front().first.first;
            int y=q.front().first.second;
            int cnt=q.front().second;
            q.pop();
           
            count=max(count, cnt);
            vector<int> dy={-1,0,1,0};
            vector<int> dx={0,-1,0,1};
            for(int i=0;i<4;i++){
                int kx=x+dx[i];
                int ky=y+dy[i];
                if(kx<0 || ky<0 || kx>=m || ky>=n || vis[kx][ky]==1 || grid[kx][ky]==2 || grid[kx][ky]==0){
                    continue;
                }
                else{
                    q.push({{kx,ky},cnt+1});
                    vis[kx][ky]=1;
                }
            }

        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==0 && grid[i][j]==1)
                return -1;
            }
        }
        return count;
    }
};