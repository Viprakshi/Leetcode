class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int s_len = s.size();
        int total = 1 << k;
        if (s_len - k + 1 < total) return false;
        unordered_set<string> seen;
        for (int i = 0; i + k <= s_len; ++i)
            seen.insert(move(s.substr(i, k)));
        return seen.size() == total;
    }
};