class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n+1);
        int var1=0;
        int var2=0;

        for(int i=2;i<=n;i++){
            int curr=min(var2 + cost[i-1],
                        var1 + cost[i-2]);
            var1=var2;
            var2=curr;
        }
        return var2;
    }
};