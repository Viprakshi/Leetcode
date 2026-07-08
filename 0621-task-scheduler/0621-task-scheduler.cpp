class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int, vector<int>> pq;
        unordered_map<char, int> mpp;
        queue<pair<int,int>> q;
        for(char ch:tasks){
            mpp[ch]++;
        }
        for(auto it:mpp){
            pq.push(it.second);
        }
        int ans=0;
        while(!pq.empty() || !q.empty()){
            ans++;
            if(!pq.empty()){
                int cnt=pq.top();
                pq.pop();
                if(cnt>1)
                q.push({--cnt,ans+n});
            }
            if (!q.empty() && q.front().second == ans) {
                pq.push(q.front().first);
                q.pop();
            }

        }
        return ans;

    }
};