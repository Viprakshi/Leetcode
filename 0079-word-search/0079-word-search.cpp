class Solution {
public:
    bool check(vector<vector<char>>& board, int i, int j, string word, string curr,vector<vector<int>>& vis, int ind)
    {
        if(ind==word.length()) return true;
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || vis[i][j]==1 || board[i][j]!=word[ind])
        {
            return false;
        }
        if(curr==word) return true;
        vis[i][j]=1;
        bool left=check(board, i, j-1, word, curr+board[i][j],vis,ind+1);
        bool right=check(board, i, j+1, word, curr+board[i][j],vis,ind+1);
        bool up=check(board, i-1, j, word, curr+board[i][j],vis,ind+1);
        bool down=check(board, i+1, j, word, curr+board[i][j],vis,ind+1);
        vis[i][j]=0;
        return up || down || left || right;
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>> vis(board.size(), vector<int>(board[0].size(),0));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(check(board, i, j, word,"",vis,0)) return true;
            }
        }
        return false;
    }
};