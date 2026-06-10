class Solution {
public:
    struct Node {
        long long val;
        int l, r;
        bool operator<(const Node& other) const {
            return val < other.val;
        }
    };

    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        int LOG = 0;
        while ((1 << LOG) <= n) LOG++;

        vector<vector<int>> mx(LOG, vector<int>(n));
        vector<vector<int>> mn(LOG, vector<int>(n));

        for (int i = 0; i < n; i++) {
            mx[0][i] = nums[i];
            mn[0][i] = nums[i];
        }

        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                mx[j][i] = max(mx[j - 1][i],
                               mx[j - 1][i + (1 << (j - 1))]);
                mn[j][i] = min(mn[j - 1][i],
                               mn[j - 1][i + (1 << (j - 1))]);
            }
        }

        vector<int> lg(n + 1);
        for (int i = 2; i <= n; i++)
            lg[i] = lg[i / 2] + 1;

        auto getVal = [&](int l, int r) -> long long {
            int len = r - l + 1;
            int j = lg[len];

            int maxi = max(mx[j][l], mx[j][r - (1 << j) + 1]);
            int mini = min(mn[j][l], mn[j][r - (1 << j) + 1]);

            return 1LL * maxi - mini;
        };

        priority_queue<Node> pq;

        for (int l = 0; l < n; l++) {
            pq.push({getVal(l, n - 1), l, n - 1});
        }

        long long ans = 0;

        while (k-- && !pq.empty()) {
            auto [val, l, r] = pq.top();
            pq.pop();

            ans += val;

            if (r > l) {
                pq.push({getVal(l, r - 1), l, r - 1});
            }
        }

        return ans;
    }
};