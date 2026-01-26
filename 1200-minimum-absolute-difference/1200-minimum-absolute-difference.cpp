class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;
        sort(arr.begin(),arr.end());
        int min_sum=INT_MAX;
        for(int i=1;i<arr.size();i++){
            min_sum=min(min_sum,arr[i]-arr[i-1]);
        }
        for(int j=0;j<arr.size()-1;j++){
            if(arr[j+1]-arr[j]==min_sum){
                ans.push_back({arr[j],arr[j+1]});
            }
        }
        return ans;
    }
};