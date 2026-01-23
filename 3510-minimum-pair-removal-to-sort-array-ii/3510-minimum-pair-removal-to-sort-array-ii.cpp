class Solution {
public:
    using ll = long long;

    int minimumPairRemoval(vector<int>& nums1) {
        int n = nums1.size();
        if (n <= 1) return 0;

        vector<ll> nums(n);
        for (int i = 0; i < n; i++) nums[i] = nums1[i];

        vector<int> prev_idx(n), next_idx(n);
        vector<char> alive(n, 1);
        for (int i = 0; i < n; i++) {
            prev_idx[i] = i - 1;
            next_idx[i] = (i + 1 < n ? i + 1 : -1);
        }

        auto bad_edge = [&](int i) -> int {
            if (i == -1) return 0;
            int j = next_idx[i];
            if (j == -1) return 0;
            return nums[i] > nums[j];
        };

        ll bad_cnt = 0;
        for (int i = 0; i < n; i++) bad_cnt += bad_edge(i);

        using state = pair<ll, int>;
        priority_queue<state, vector<state>, greater<state>> pq;

        vector<ll> ver(n, 0);

        auto push_pair = [&](int i) {
            if (i == -1) return;
            int j = next_idx[i];
            if (j == -1) return;
            ver[i]++;
            pq.push({nums[i] + nums[j], i});
        };

        for (int i = 0; i < n; i++) {
            if (next_idx[i] != -1) pq.push({nums[i] + nums[next_idx[i]], i});
        }

        int ops = 0, alive_cnt = n;

        while (alive_cnt > 1 && bad_cnt > 0) {
            ll sum;
            int i;

            while (true) {
                sum = pq.top().first;
                i = pq.top().second;
                pq.pop();

                if (i == -1 || !alive[i]) continue;
                int j = next_idx[i];
                if (j == -1 || !alive[j]) continue;
                if (nums[i] + nums[j] != sum) continue;

                break;
            }

            int j = next_idx[i];
            int left = prev_idx[i];
            int right = next_idx[j];

            bad_cnt -= bad_edge(left);
            bad_cnt -= bad_edge(i);
            bad_cnt -= bad_edge(j);

            nums[i] += nums[j];
            alive[j] = 0;
            alive_cnt--;
            ops++;

            next_idx[i] = right;
            if (right != -1) prev_idx[right] = i;

            bad_cnt += bad_edge(left);
            bad_cnt += bad_edge(i);

            if (left != -1) pq.push({nums[left] + nums[i], left});
            if (right != -1) pq.push({nums[i] + nums[right], i});
        }

        return ops;
    }
};
