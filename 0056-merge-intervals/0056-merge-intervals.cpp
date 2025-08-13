class Solution {
public:
    static bool cmp(vector<int>& a,vector<int>& b){
        return a[0]<b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> ans;
        pair<int, int> curr = { intervals[0][0], intervals[0][1] };
        for(int i=0; i<intervals.size();i++){
            if(curr.second>=intervals[i][0]) curr.second=max(intervals[i][1],curr.second);
            else{
                ans.push_back({curr.first,curr.second});
                curr={intervals[i][0], intervals[i][1]};
            }

        } 
        ans.push_back({curr.first,curr.second});
        return ans;
    }
};