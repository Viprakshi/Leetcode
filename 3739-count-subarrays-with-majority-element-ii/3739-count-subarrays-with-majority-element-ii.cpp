class Solution {
    vector<int> bit;
    int sz;

    void update(int i) {
        for (; i <= sz; i += i & -i)
            bit[i]++;
    }

    int query(int i) {
        int s = 0;
        for (; i > 0; i -= i & -i)
            s += bit[i];
        return s;
    }

public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        sz = 2 * n + 1;
        bit.assign(sz + 1, 0);
        int s = n + 1;
        update(s);
        long long ans = 0;
        for (int x : nums) {
            s += (x == target) ? 1 : -1;
            ans += query(s - 1);
            update(s);
        }
        return ans;
    }
};