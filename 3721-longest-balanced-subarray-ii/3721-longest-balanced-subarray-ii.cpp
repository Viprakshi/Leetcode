class SegTree {
    struct N {
        int l, r, mn, mx, lazy;
    };
    vector<N> t;

    void apply(int u, int v) {
        t[u].mn += v; t[u].mx += v; t[u].lazy += v;
    }

    void push(int u) {
        if (t[u].lazy) {
            apply(u<<1, t[u].lazy);
            apply(u<<1|1, t[u].lazy);
            t[u].lazy = 0;
        }
    }

    void pull(int u) {
        t[u].mn = min(t[u<<1].mn, t[u<<1|1].mn);
        t[u].mx = max(t[u<<1].mx, t[u<<1|1].mx);
    }

    void build(int u, int l, int r) {
        t[u] = {l, r, 0, 0, 0};
        if (l == r) return;
        int m = (l + r) >> 1;
        build(u<<1, l, m);
        build(u<<1|1, m+1, r);
    }

public:
    SegTree(int n) : t(n<<2) { build(1, 0, n); }

    void add(int u, int l, int r, int v) {
        if (t[u].l >= l && t[u].r <= r) {
            apply(u, v);
            return;
        }
        push(u);
        int m = (t[u].l + t[u].r) >> 1;
        if (l <= m) add(u<<1, l, r, v);
        if (r > m) add(u<<1|1, l, r, v);
        pull(u);
    }

    int find(int u, int x) {
        if (t[u].l == t[u].r) return t[u].l;
        push(u);
        if (t[u<<1].mn <= x && x <= t[u<<1].mx)
            return find(u<<1, x);
        return find(u<<1|1, x);
    }
};

class Solution {
public:
    int longestBalanced(vector<int>& a) {
        int n = a.size(), cur = 0, ans = 0;
        SegTree st(n);
        unordered_map<int,int> last;

        for (int i = 1; i <= n; i++) {
            int d = (a[i-1] & 1) ? 1 : -1;
            if (last.count(a[i-1])) {
                st.add(1, last[a[i-1]], n, -d);
                cur -= d;
            }
            last[a[i-1]] = i;
            st.add(1, i, n, d);
            cur += d;
            ans = max(ans, i - st.find(1, cur));
        }
        return ans;
    }
};
