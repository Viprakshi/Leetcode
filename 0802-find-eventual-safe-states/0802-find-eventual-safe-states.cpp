class Solution {
public:
    bool dfs(int i,vector<vector<int>>& graph,vector<int>& safe,vector<int>& vis, vector<int>& pathvis){
        pathvis[i]=1;
        vis[i]=1;
        for(auto adj: graph[i]){
            if(!vis[adj]){
                if(dfs(adj, graph, safe,vis, pathvis)) return true;
            }
            else if(pathvis[adj]==1) return true;
        }
        pathvis[i]=0;
        safe[i]=1;
        return false;

    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int m=graph.size();
        vector<int> vis(m,0);
        vector<int> safe(m,0);
        vector<int> pathvis(m,0);
        for(int i=0;i<graph.size();i++){
            dfs(i, graph, safe, vis,pathvis);
        }
        vector<int> ans;
        for(int i=0;i<m;i++){
            if(safe[i]==1) ans.push_back(i);
        }
        return ans;
    }
};