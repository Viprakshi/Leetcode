class Solution {
public:
    bool dfs(int i, int c, vector<vector<int>>& graph, vector<int>& color){
        color[i]=c;
        for(auto adj: graph[i]){
            if(color[adj]==-1){
                if(dfs(adj,!c,graph,color)==false) return false;
            }
            else{
                if(color[adj]==c)
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int m=graph.size();
        vector<int> color(m,-1);
        for(int i=0;i<m;i++){
            if(color[i]==-1){
                if(dfs(i,0,graph,color)==false)
                return false;
            }
        }
        return true;
    }
};