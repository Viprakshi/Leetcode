class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, int& num_of_paths, int can_vis){
    if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j]==-1)
        return;

    if(grid[i][j] == 2 && can_vis == 0){
        num_of_paths += 1;
        return;
    }

    if(grid[i][j] == 0 || grid[i][j] == 1){
    int temp = grid[i][j];
    grid[i][j] = -1;
    dfs(grid, i+1, j, num_of_paths, can_vis-1);
    dfs(grid, i-1, j, num_of_paths, can_vis-1);
    dfs(grid, i,   j+1, num_of_paths, can_vis-1);
    dfs(grid, i,   j-1, num_of_paths, can_vis-1);
    grid[i][j] = temp; 
}
}
    int uniquePathsIII(vector<vector<int>>& grid) {
        int num_of_paths=0;
        int cant_vis=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==-1)
                    cant_vis++;
            }
        }
        int vis=(grid.size()*grid[0].size())-cant_vis-2;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1)
                    dfs(grid,i,j,num_of_paths,vis+1);
            }
        }
        return num_of_paths;
    }
};