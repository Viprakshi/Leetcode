class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        vector<int> curr;
        curr=intervals[0];
        for(int i=1;i<intervals.size();i++){
            auto x=intervals[i];
            if(x[0]<=curr[1]){
                curr[1]=max(curr[1], x[1]);
            }
            else{
                ans.push_back(curr);
                curr=intervals[i];
            }
        }
        ans.push_back(curr);
        return ans;
    }
};