class Solution {
public:
    void dfs(vector<vector<int>>& image, int r, int c, int color, int oldcolor){
        int m=image.size(), n=image[0].size();
        if(r>=m || c>=n || r<0 || c<0) return;
        if(image[r][c]!= oldcolor) return;
        image[r][c]=color;
        dfs(image, r+1, c, color, oldcolor);
        dfs(image, r, c+1, color,oldcolor);
        dfs(image, r-1, c, color, oldcolor);
        dfs(image, r, c-1, color, oldcolor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldcolor=image[sr][sc];
        if(oldcolor==color) return image;
        dfs(image,sr, sc, color, oldcolor);
        return image;
    }
};