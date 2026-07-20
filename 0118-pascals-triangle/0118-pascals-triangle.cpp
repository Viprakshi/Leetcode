class Solution {
public:
    vector<int> gen(int n){
        vector<int> x;
        int y=1;
        for(int i=1;i<=n;i++){
             x.push_back(y);
            y=y*(n-i);
            y=y/(i);
           
        }
        return x;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=1;i<=numRows;i++){
            vector<int> row=gen(i);
            ans.push_back(row);
        }
        return ans;
    }
};