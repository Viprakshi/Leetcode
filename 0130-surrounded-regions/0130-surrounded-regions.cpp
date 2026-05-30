class Solution {
public:
    void dfs(int x, int y, vector<vector<int>>& vis,vector<vector<char>>& board){
        vis[x][y]=1;
        vector<int> deltarow={-1,0,1,0};
        vector<int> deltacol={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nr=x+deltarow[i];
            int nc=y+deltacol[i];
            if(nr>=board.size() || nc>=board[0].size() || nr<0 || nc<0){
                continue;
            }
            else if(!vis[nr][nc] && board[nr][nc]=='O'){
                dfs(nr, nc, vis, board);
            }
        }

    }
    void solve(vector<vector<char>>& board) {
        int m=board.size(), n=board[0].size();
        vector<vector<int>> vis(m, vector<int>(n,0));
        // Top row
for(int j = 0; j < n; j++) {
    if(board[0][j] == 'O') {
        dfs(0, j, vis, board);
    }
}

// Bottom row
for(int j = 0; j < n; j++) {
    if(board[m-1][j] == 'O') {
        dfs(m-1, j, vis, board);
    }
}

// Left column
for(int i = 0; i < m; i++) {
    if(board[i][0] == 'O') {
        dfs(i, 0, vis, board);
    }
}

// Right column
for(int i = 0; i < m; i++) {
    if(board[i][n-1] == 'O') {
        dfs(i, n-1, vis, board);
    }
}

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && board[i][j]=='O')
                board[i][j]='X';
            }
        }
    }
};