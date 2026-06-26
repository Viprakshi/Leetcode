class Solution {
public:
    int cal(vector<int>& nums,int curr, vector<int>& dp ){
        if(curr==0) return nums[0];
        dp[0]=nums[0];
        dp[1]=max(nums[1],nums[0]);
        for(int i=2;i<nums.size();i++){
            int inc=dp[i-2]+nums[i];
            int ninc=dp[i-1];
            dp[i]=max(inc, ninc);
        }
        return dp[curr];
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return cal(nums,nums.size()-1, dp);
    }
};