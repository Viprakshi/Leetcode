class Solution {
public:
    bool dfs(int i,vector<int>& path, vector<int>& vis, stack<int>& st, vector<vector<int>>& adj){
        vis[i]=1;
        path[i]=1;
        for(auto x:adj[i]){
            if(!vis[x]){
                if(dfs(x,path,vis,st,adj)==true) return true;
            }
            else if(path[x]){
                return true;
            }

        }
        path[i]=0;
        st.push(i);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for (auto &it : prerequisites) {
            adj[it[1]].push_back(it[0]);
        }
        vector<int> ans;
        stack<int> st;
        vector<int> vis(numCourses,0);
        vector<int> path(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs(i,path,vis,st,adj)==true){
                   return ans;
                }
            }
        }
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};