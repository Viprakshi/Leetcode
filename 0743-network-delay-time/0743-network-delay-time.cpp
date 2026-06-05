class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for(auto time:times){
            adj[time[0]].push_back({time[1],time[2]});
        }

        vector<int> time(n+1,INT_MAX);
        queue<pair<int,int>> q;
        time[k]=0;
        q.push({k,0});
        int ans=0;
        while(!q.empty()){
            int node=q.front().first;
            int time_node=q.front().second;
            q.pop();
            for(auto adj_node:adj[node]){
                int node_adj=adj_node.first;
                int time_adj=adj_node.second;
                if(time_node+time_adj<time[node_adj]){
                    time[node_adj]=time_node+time_adj;
                    q.push({node_adj, time_node+time_adj});
                }
                
            }
        }

for(int i=1;i<=n;i++){
    if(time[i]==INT_MAX) return -1;
    ans = max(ans, time[i]);
}
        return ans;
    }
};