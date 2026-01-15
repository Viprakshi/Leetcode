class Solution {
public:
    int div(vector<int>& nums, int d) {
        int sum = 0;
        for (int x : nums)
            sum += (x + d - 1) / d;
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1, high = *max_element(nums.begin(), nums.end());
        int ans = high;

        while (low <= high) {
            int mid = (low + high) / 2;
            int val = div(nums, mid);

            if (val <= threshold) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
