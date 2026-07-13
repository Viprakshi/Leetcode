class Solution {
public:
    static const int MOD = 1e9 + 7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        vector<int> p;
        vector<long long> ps, pn;

        long long sm = 0, nm = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '0') {
                int d = s[i] - '0';
                p.push_back(i);
                sm += d;
                ps.push_back(sm);
                nm = (nm * 10 + d) % MOD;
                pn.push_back(nm);
            }
        }

        int k = p.size();
        vector<long long> pw(k + 1, 1);
        for (int i = 1; i <= k; i++)
            pw[i] = (pw[i - 1] * 10) % MOD;

        vector<int> ans;

        for (auto &q : queries) {
            auto l = lower_bound(p.begin(), p.end(), q[0]);
            auto r = upper_bound(p.begin(), p.end(), q[1]);

            if (l == p.end() || l == r) {
                ans.push_back(0);
                continue;
            }

            int i = l - p.begin();
            int j = r - p.begin() - 1;

            long long s = ps[j] - (i ? ps[i - 1] : 0);
            int len = j - i + 1;

            long long x = pn[j];
            if (i)
                x = (x - pn[i - 1] * pw[len] % MOD + MOD) % MOD;

            ans.push_back(x * s % MOD);
        }

        return ans;
    }
};