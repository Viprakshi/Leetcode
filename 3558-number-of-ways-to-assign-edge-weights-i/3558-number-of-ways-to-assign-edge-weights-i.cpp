class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj,
             vector<int>& vis, int& height, int h) {

        vis[node] = 1;
        height = max(height, h);

        for (auto x : adj[node]) {
            if (!vis[x]) {
                dfs(x, adj, vis, height, h + 1);
            }
        }
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;  

        vector<vector<int>> adj(n + 1);

        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int height = 0;
        vector<int> vis(n + 1, 0);

        dfs(1, adj, vis, height, 0);

        long long ans = 1;
        int mod = 1e9 + 7;

        for (int i = 0; i < height - 1; i++) {
            ans = (ans * 2) % mod;
        }

        return ans;
    }
};