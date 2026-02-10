class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<int, int> even, odd;
            int even_cnt = 0, odd_cnt = 0;

            for (int j = i; j < n; j++) {
                if (nums[j] % 2 == 0) {
                    if (even[nums[j]] == 0)
                        even_cnt++;
                    even[nums[j]]++;
                } else {
                    if (odd[nums[j]] == 0)
                        odd_cnt++;
                    odd[nums[j]]++;
                }

                if (even_cnt == odd_cnt) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};
