class Solution {
public:
    void generate(vector<int>& arr, vector<int>& temp, vector<vector<int>>& ans, int sum, int target, int ind ){
        if(sum==target){
            ans.push_back(temp);
            return;
        }

        for(int i=ind;i<arr.size();i++){
            if(i>ind && arr[i]==arr[i-1]){
                continue;
            }
            if(sum+arr[i]>target)
            break;
            else {
                temp.push_back(arr[i]);
                generate(arr,temp,ans,sum+arr[i],target,i+1);
                temp.pop_back();
            }
            
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        generate(candidates, temp, ans, 0, target, 0);
        return ans;
    }
};