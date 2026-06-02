class Solution {
public:
    bool dfs(int i, vector<vector<int>>& p,vector<int>& vis,vector<int>& path){
        vis[i]=1;
        path[i]=1;
        for(auto adj: p[i]){
            if(!vis[adj]){
                if(dfs(adj,p,vis,path)==true) return true;
            } 
            else if(path[adj]==1){
                return true;
            }
        }
        path[i]=0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> x(numCourses);

        for (auto &it : prerequisites) {
            x[it[1]].push_back(it[0]);
        }
        vector<int> vis(numCourses,0);
        vector<int> path(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs(i,x,vis,path)==true) return false;
            }
        }
        return true;
    }
};