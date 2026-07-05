class Solution {
public:
    bool isValid(vector<vector<char>>& board,int i, int j, int k){
        for(int x=0;x<9;x++){
            if(board[i][x]==k+'0') return false;
        }
        for(int x=0;x<9;x++){
            if(board[x][j]==k+'0') return false;
        }
        int r=3*(i/3);
        int c=3*(j/3);
        for(int x=0;x<3;x++){
            for(int y=0;y<3;y++){
                if(board[x+r][y+c]==k+'0') return false;
            }
        }
        return true;
    }
    bool generate(vector<vector<char>>& board){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[1].size();j++){
                if(board[i][j]=='.'){
                    for(int k=1;k<=9;k++){
                        if(isValid(board, i, j, k)){
                            board[i][j]=k+'0';
                            if(generate(board)) return true;
                            board[i][j]='.';
                        }
                    }
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