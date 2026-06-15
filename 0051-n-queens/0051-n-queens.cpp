class Solution {
public:
    vector<vector<string>> ans;

    bool safe(vector<string>& board, int row, int col, int n) {
        // column
        for(int r=0;r<row;r++) {
            if(board[r][col]=='Q')
                return false;
        }
        // upper-left diagonal
        int r=row-1, c=col-1;
        while(r>=0 && c>=0) {
            if(board[r][c]=='Q')
                return false;
            r--;
            c--;
        }

        // upper-right diagonal
        r=row-1;
        c=col+1;
        while(r>=0 && c<n) {
            if(board[r][c]=='Q')
                return false;
           r--;
            c++;
        }

        return true;
    }

    void solve(vector<string>& board, int row, int n) {
        if(row==n) {
            ans.push_back(board);
            return;
        }

        for(int col=0; col<n; col++) {
            if(safe(board,row,col,n)) {
                board[row][col]='Q';
                solve(board,row+1,n);
                board[row][col]='.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        solve(board,0,n);
        return ans;
    }
};