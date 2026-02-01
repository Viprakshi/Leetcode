class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
       unordered_map<int, unordered_map<char, int>> mpp_row;
       unordered_map<int, unordered_map<char, int>> mpp_col;
       unordered_map<int, unordered_map<char, int>> mpp_box;

       for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            if(board[i][j]=='.') continue;
            char num=board[i][j];
            int box_index=(i/3)*3+(j/3);

            if(mpp_row[i][num]>0 || mpp_col[num][j]>0 || mpp_box[box_index][num]>0){
                return false;
            }

            mpp_row[i][num]++;
            mpp_col[num][j]++;
            mpp_box[box_index][num]++;
        }
        
       }
       return true;
       
    }
};