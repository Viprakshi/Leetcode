class Solution {
public:
    int cal(vector<int>& nums,int curr, vector<int>& dp ){
        if(curr<0) return 0;
        if(curr==0) return nums[0];
        if(dp[curr]!=-1) return dp[curr];
    
        int include=nums[curr]+cal(nums, curr-2,dp);
        int not_include=cal(nums,curr-1,dp);
        dp[curr]=max(include, not_include);
        return dp[curr];
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return cal(nums,nums.size()-1, dp);
    }
};