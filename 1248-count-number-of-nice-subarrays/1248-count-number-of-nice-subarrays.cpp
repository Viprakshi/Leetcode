class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int left = 0, right = 0;
        int odd = 0;
        int count = 0;
        int prefix = 0;

        while(right < nums.size()) {
            if(nums[right] % 2) {
                odd++;
                prefix = 0;
            }

            while(odd == k) {
                prefix++;
                if(nums[left] % 2)
                    odd--;
                left++;
            }
            count+=prefix;
            right++;
        }

        return count;
    }
};