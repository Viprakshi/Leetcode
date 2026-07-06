class Solution {
public:
    void gen(vector<int>& arr, int target, vector<vector<int>>& ans, int curr_sum,int curr_ind, vector<int>& curr_ans){
        if(curr_sum>target || curr_ind==arr.size()){
            if(curr_sum==target){
                ans.push_back(curr_ans);
            }
            return;
        }
        gen(arr,target,ans,curr_sum,curr_ind+1,curr_ans);
        curr_ans.push_back(arr[curr_ind]);
        gen(arr,target,ans,curr_sum+arr[curr_ind],curr_ind,curr_ans);
        curr_ans.pop_back();

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        gen(candidates, target, ans,0,0,curr);
        return ans;
    }
};