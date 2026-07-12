class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        vector<int> x=intervals[0];
        for(int i=0;i<intervals.size();i++){
            auto y=intervals[i];
            if(x[1] >= y[0]){
                x[0]=min(x[0],y[0]);
                x[1]=max(x[1],y[1]);
            }
            else{
                ans.push_back(x);
                x=intervals[i];
            }
        }
        ans.push_back(x);
        return ans;
    }
};