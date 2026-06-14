class Solution {
public:
     void generate( vector<int>& arr, vector<vector<int>>& ans,  vector<int>& temp,int ind ){
            ans.push_back(temp);
        
        for(int i=ind;i<arr.size();i++){
            if(i>ind && arr[i]==arr[i-1])
            continue;
            temp.push_back(arr[i]);
            generate(arr,ans,temp,i+1);
            temp.pop_back();
            
        }
        
        
        
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(),nums.end());
        generate(nums,ans,temp,0);
        return ans;
    }
};