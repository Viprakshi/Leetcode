class Solution {
public:
    bool cal(vector<int>& nums, vector<vector<int>>& dp, int curr, int left) {
        if (left == 0) return true;
        if (curr >= nums.size() || left < 0) return false;
        if (dp[curr][left] != -1)
            return dp[curr][left];
        bool notTake = cal(nums, dp, curr + 1, left);
        bool take = cal(nums, dp, curr + 1, left - nums[curr]);
        return dp[curr][left] = take || notTake;
    }

    bool canPartition(vector<int>& nums) {
        int totSum = accumulate(nums.begin(), nums.end(), 0);
        if (totSum % 2) return false;
        int target = totSum / 2;
        vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1));
        return cal(nums, dp, 0, target);
    }
};