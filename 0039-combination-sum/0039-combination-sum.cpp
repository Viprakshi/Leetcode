class Solution {
public:
    void generate(vector<int>& arr, int target,vector<vector<int>>& ans, vector<int>& temp, int pos,int sum){
        if(sum==target){
            ans.push_back(temp);
            return;
        }
        if(sum>target || pos>=arr.size()) return;
        generate(arr,target,ans,temp,pos+1,sum);
        temp.push_back(arr[pos]);
        generate(arr,target,ans,temp,pos,sum+arr[pos]);
        temp.pop_back();

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        generate(candidates, target, ans,temp,0,0);
        return ans;
    }
};