class Solution {
public:
    int minJumps(vector<int>& nums, int position, vector<int>& dp) {

        if(position >= nums.size()-1) return 0;
        if(nums[position] == 0) return INT_MAX;

        if(dp[position] != -1)
            return dp[position];

        int minStep = INT_MAX;

        for(int jump=1; jump<=nums[position]; jump++) {

            int subResult =
                minJumps(nums, position+jump, dp);

            if(subResult != INT_MAX)
                minStep = min(minStep, 1 + subResult);
        }

        return dp[position] = minStep;
    }

    int jump(vector<int>& nums) {

        vector<int> dp(nums.size(), -1);

        return minJumps(nums, 0, dp);
    }
};