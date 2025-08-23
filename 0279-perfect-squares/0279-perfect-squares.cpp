class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, n + 1);
        dp[0] = 0;

        for (int j = 1; j <= n; j++) {
            for (int i = 1; i*i <= j; i++) {
                int square = i * i;
                dp[j] = min(dp[j], 1 + dp[j - square]);
            }
        }

        return dp[n];
    }
};
