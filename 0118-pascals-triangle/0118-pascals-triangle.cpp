class Solution {
public:
    vector<int> generate_row(int n){
        int ans=1;
        vector<int> row;
        for(int i=1;i<=n;i++){
            row.push_back(ans);
            ans=ans*(n-i);
            ans=ans/(i);  
        }
        return row;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=1;i<=numRows;i++){
            vector<int> row=generate_row(i);
            ans.push_back(row);
        }
        return ans;
    }
};