class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size(), n=mat[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<pair<pair<int,int>, int>> q;

        for(int i=0; i<m;i++){
            for(int j=0; j<n; j++){
                if(mat[i][j]==0){
                    vis[i][j]=1;
                    q.push({{i,j},0});
                }
            }
        }
        
        vector<int> deltarow={-1,0,1,0};
        vector<int> deltacol={0,1,0,-1};
        while(!q.empty()){
            int x=q.front().first.first;
            int y=q.front().first.second;
            int z=q.front().second;
            q.pop();
            dist[x][y]=min(z,dist[x][y]);
            
            for(int i=0;i<4;i++){
                int nr=x+deltarow[i];
                int nc=y+deltacol[i];
                if(nr<0 || nc<0 || nr>=m || nc>=n) continue;
                if(!vis[nr][nc])
                {
                    vis[nr][nc]=1;
                    q.push({{nr,nc},z+1});
                }

            }

        }
        return dist;

    }
};