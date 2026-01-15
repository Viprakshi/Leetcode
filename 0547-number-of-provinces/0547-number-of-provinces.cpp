class Solution {
public:
    void dfs(int city, vector<vector<int>>& isConnected, vector<int>& vis) {
        vis[city] = 1;
        for (int next = 0; next < isConnected.size(); next++) {
            if (isConnected[city][next] == 1 && !vis[next]) {
                dfs(next, isConnected, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n, 0);
        int provinces = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                provinces++;
                dfs(i, isConnected, vis);
            }
        }
        return provinces;
    }
};
