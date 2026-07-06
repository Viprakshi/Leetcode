class Solution {
public:
    bool isValid(vector<string>& board, int i, int j) {
    for(int x = 0; x < i; x++) {
        if(board[x][j] == 'Q')
            return false;
    }

    for(int x = i - 1, y = j - 1; x >= 0 && y >= 0; x--, y--) {
        if(board[x][y] == 'Q')
            return false;
    }

    for(int x = i - 1, y = j + 1; x >= 0 && y < board.size(); x--, y++) {
        if(board[x][y] == 'Q')
            return false;
    }

    return true;
}
    void generate(vector<vector<string>>& ans, vector<string>& board, int n, int curr){
        if(curr==n){
            ans.push_back(board);
            return;
        }
        
        for(int i=0;i<n;i++){
            if(isValid(board,curr,i)){
                board[curr][i]='Q';
                generate(ans,board,n,curr+1);
                board[curr][i]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        generate(ans,board,n,0);
        return ans;
    }
};