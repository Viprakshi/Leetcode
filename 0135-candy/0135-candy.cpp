class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> ans(n, 1);

        // Handle up slopes
        for(int i = 1; i < n; i++) {
            if(ratings[i] > ratings[i - 1]) {
                ans[i] = ans[i - 1] + 1;
            }
        }

        // Handle down slopes
        for(int i = n - 2; i >= 0; i--) {
            if(ratings[i] > ratings[i + 1]) {
                ans[i] = max(ans[i], ans[i + 1] + 1);
            }
        }

        int total = 0;
        for(int x : ans) total += x;

        return total;
    }
};