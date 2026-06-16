class Solution {
public:
    vector<vector<int>> ans;
    bool isValid(vector<vector<char>>& board, int x, int y, char m){
        //horizontal
        for(int i=0;i<9;i++){
            if(board[x][i]==m) return false; 
        }
        //vertical
        for(int j=0;j<9;j++){
            if(board[j][y]==m) return false;
        }
        int r=3*(x/3);
        int c=3*(y/3);

        for(int i=0;i<3;i++) {
            for(int j=0;j<3;j++){
                if (board[r + i][c + j] == m)
                    return false;
            }
        }

        return true;

    }
    bool generate(vector<vector<char>>& board){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(board[i][j]=='.'){
                    for(char x='1';x<='9';x++){
                        if(isValid(board, i, j, x)){
                            board[i][j]=x;
                            if(generate(board)) return true;
                            board[i][j]='.';
                        }
                    }
                    //if nothing valid
                    return false;
                }
            }
        }
        return true;

    }
    void solveSudoku(vector<vector<char>>& board) {
        generate(board);

    }
};