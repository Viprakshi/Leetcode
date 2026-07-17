class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());

        vector<long long> freq(mx + 1, 0);

        for (int x : nums)
            freq[x]++;

        vector<long long> gcdCnt(mx + 1, 0);

        for (int d = mx; d >= 1; d--) {
            long long cnt = 0;

            for (int j = d; j <= mx; j += d)
                cnt += freq[j];

            gcdCnt[d] = cnt * (cnt - 1) / 2;

            for (int j = 2 * d; j <= mx; j += d)
                gcdCnt[d] -= gcdCnt[j];
        }

        vector<long long> pref(mx + 1, 0);

        for (int i = 1; i <= mx; i++)
            pref[i] = pref[i - 1] + gcdCnt[i];

        vector<int> ans;

        for (long long q : queries) {
            int g = lower_bound(pref.begin() + 1, pref.end(), q + 1) - pref.begin();
            ans.push_back(g);
        }

        return ans;
    }
};