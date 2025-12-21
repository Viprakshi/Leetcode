class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price=INT_MAX, max_profit=INT_MIN;
        for(int price:prices){
            min_price=min(price,min_price);
            max_profit=max(max_profit,price-min_price);
        }
        return max_profit;
    }
};