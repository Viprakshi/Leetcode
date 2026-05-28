class Solution {
public:
    void dfs(int node, vector<int> adjlist[], vector<int>& visited){
        visited[node]=1;
        
        for(auto i: adjlist[node]){
            if(!visited[i])
            dfs(i,adjlist,visited);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        // matrix --> list 
        int n= isConnected.size();
        vector<int> adjlist[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    adjlist[i].push_back(j);
                    adjlist[j].push_back(i);
                }
            }
        }
        //count 
        int count=0;
        vector<int> visited(n,0);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                count++;
                dfs(i,adjlist,visited);
            }
        }
        return count;
    }
};