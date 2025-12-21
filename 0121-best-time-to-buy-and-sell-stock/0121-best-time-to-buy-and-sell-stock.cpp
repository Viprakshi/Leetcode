class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int j=prices.size()-1;
        int i=j-1;
        int max_profit=0;
        int profit=0;
        while(i>=0){
            if(prices[i]>prices[j]){
                j=i;
            }
            if(prices[i]<prices[j]){
                profit=max(profit,prices[j]-prices[i]);
            }
            i--;
            
        }
        return profit;
    }
};