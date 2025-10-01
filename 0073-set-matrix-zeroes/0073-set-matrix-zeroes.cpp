class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row=matrix.size(), column=matrix[0].size();
        int col=-1;
        for(int i=0;i<row;i++){
            for(int j=0;j<column;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    if(j==0) col=0;
                    else matrix[0][j]=0;
                }
            }
        }
        
        for(int x=1;x<row;x++){
            for(int y=1;y<column;y++){
                if(matrix[x][0]==0 || matrix[0][y]==0){
                    matrix[x][y]=0;
                }
            }
        }
        if(matrix[0][0]==0) 
        {
            for(int j=0;j<column;j++){
                matrix[0][j]=0;
            }
        }
        if(col==0) 
        {
            for(int i=0;i<row;i++){
                matrix[i][0]=0;
            }
        }
        
        
    }
};