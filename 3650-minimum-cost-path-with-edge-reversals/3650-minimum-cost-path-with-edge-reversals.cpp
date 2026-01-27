class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> out(n), in(n);
        for (auto &e : edges) {
            out[e[0]].push_back({e[1], e[2]});
            in[e[1]].push_back({e[0], e[2]});
        }

        const long long INF = 4e18;
        vector<vector<long long>> dist(n, vector<long long>(2, INF));
        priority_queue<array<long long,3>, vector<array<long long,3>>, greater<>> pq;

        dist[0][0] = 0;
        pq.push({0, 0, 0});

        while (!pq.empty()) {
            auto [d, u, used] = pq.top(); pq.pop();
            if (d != dist[u][used]) continue;

            for (auto &[v, w] : out[u]) {
                if (d + w < dist[v][0]) {
                    dist[v][0] = d + w;
                    pq.push({d + w, v, 0});
                }
            }

            if (!used) {
                for (auto &[v, w] : in[u]) {
                    if (d + 2LL*w < dist[v][0]) {   
                        dist[v][0] = d + 2LL*w;
                        pq.push({d + 2LL*w, v, 0});
                    }
                }
            }
        }

        long long ans = min(dist[n-1][0], dist[n-1][1]);
        return ans >= INF ? -1 : ans;
    }
};
