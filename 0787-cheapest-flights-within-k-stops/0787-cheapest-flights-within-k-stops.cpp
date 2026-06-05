class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto x: flights){
            adj[x[0]].push_back({x[1],x[2]});
        }
        queue<pair<int,pair<int,int>>> q;
        vector<int> dist(n,INT_MAX);
        dist[src]=0;
        q.push({0,{src,0}});
        while(!q.empty()){
            int stops=q.front().first;
            int node=q.front().second.first;
            int d=q.front().second.second;
            q.pop();
            if(stops>k){
                continue;
            }
            for(auto a:adj[node]){
                int adjnode=a.first;
                int adjcost=a.second;
                if(d+adjcost<dist[adjnode] && stops<=k){
                    dist[adjnode]=d+adjcost;
                    q.push({stops+1,{adjnode,d+adjcost}});
                }
            }

        }
        if(dist[dst]==INT_MAX){ //we never reached the destination
            return -1;
        }
        return dist[dst];
    }
};