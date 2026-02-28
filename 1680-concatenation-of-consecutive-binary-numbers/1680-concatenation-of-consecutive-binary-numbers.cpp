class Solution {
public:
    int concatenatedBinary(int n) {
        const int MOD = 1e9 + 7;
        long result = 0;
        for (int i = 1; i <= n; i++) {
            int bits = 0, x = i;
            while (x > 0) { bits++; x >>= 1; }
            result = ((result << bits) | i) % MOD;
        }
        return result;
    }
};