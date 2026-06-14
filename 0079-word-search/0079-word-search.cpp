class Solution {
public:
    bool dfs(vector<vector<char>>& board,string word,int x, int j,vector<vector<int>>& vis,int pos){
        if(pos==word.length()-1) return true;
        vis[x][j]=1;
        vector<int> row={0,-1,0,1};
        vector<int> col={-1,0,1,0};
        
        for(int i=0;i<4;i++){
            int x_row=x+row[i];
            int x_col=j+col[i];
            
            if(x_row<0 || x_col<0 || x_row>=board.size() || x_col>=board[0].size()) continue;
            else if(!vis[x_row][x_col] && board[x_row][x_col]==word[pos+1]){
                if(dfs(board,word,x_row,x_col,vis,pos+1)) return true;
            }

        }
        vis[x][j]=0;
        
        return false;

    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size(), n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    vector<vector<int>> vis(m,vector<int>(n,0));
                    if(dfs(board,word,i,j,vis,0)) return true;
                }
            }
        }
        return false;
    }
};