class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<int>& vis, int i){
        vis[i]=1;
        for(auto node:adj[i]){
            if(vis[node]==0){
                dfs(adj, vis, node);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<vector<int>> adj(isConnected.size());
        for(int i=0;i<isConnected.size();i++)
        {
            for(int j=0;j<isConnected[i].size();j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int ans=0;
        vector<int> vis(isConnected.size(),0);
        for(int i=0;i<adj.size();i++){
            if(vis[i]==0){
                ans++;
                dfs(adj, vis, i);
            }
        }
        return ans;
    }
};