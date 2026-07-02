class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return nums[0];
        if (nums[0] != nums[1]) return nums[0];
        if (nums[n - 1] != nums[n - 2]) return nums[n - 1];

        int left = 1, right = n - 2;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
                return nums[mid];

            if (nums[mid] == nums[mid - 1]) {
                // Pair starts at mid-1
                if ((mid - 1) % 2 == 0)
                    left = mid + 1;
                else
                    right = mid - 1;
            }
            else { // nums[mid] == nums[mid + 1]
                // Pair starts at mid
                if (mid % 2 == 0)
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }

        return -1;
    }
};