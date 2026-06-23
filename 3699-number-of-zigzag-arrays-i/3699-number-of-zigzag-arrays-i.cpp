class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        const int MOD = 1e9 + 7;
        int m = r - l + 1;

        vector<int> up(m), down(m);

        for(int i = 0; i < m; i++) {
            up[i] = i;
            down[i] = m - i - 1;
        }

        for(int len = 2; len < n; len++) {
            vector<int> nu(m), nd(m);

            int cur = 0;
            for(int i = 0; i < m; i++) {
                nu[i] = cur;
                cur += down[i];
                if(cur >= MOD) cur -= MOD;
            }

            cur = 0;
            for(int i = m - 1; i >= 0; i--) {
                nd[i] = cur;
                cur += up[i];
                if(cur >= MOD) cur -= MOD;
            }

            up.swap(nu);
            down.swap(nd);
        }

        long long ans = 0;
        for(int i = 0; i < m; i++)
            ans = (ans + up[i] + down[i]) % MOD;

        return (int)ans;
    }
};