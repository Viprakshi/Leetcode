class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int ans=0;
        int i=0;
        while(i<costs.size() && coins>0){
            if(coins-costs[i]<0) return ans;
            coins=coins-costs[i];
            ans++;
            i++;
        }
        return ans;
    }
};