class Solution {
public:
    int atMostK(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        int left = 0;
        int ans = 0;

        for (int right = 0; right < nums.size(); right++) {
            mpp[nums[right]]++;

            // shrink window if distinct elements exceed k
            while (mpp.size() > k) {
                mpp[nums[left]]--;
                if (mpp[nums[left]] == 0) {
                    mpp.erase(nums[left]);
                }
                left++;
            }

            // count all subarrays ending at right
            ans += (right - left + 1);
        }

        return ans;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
};
