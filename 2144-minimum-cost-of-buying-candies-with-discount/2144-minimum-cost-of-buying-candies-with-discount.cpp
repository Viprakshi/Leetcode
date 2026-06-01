class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end());
        int k=3;
        int ans=0, i=cost.size()-1;
        while(i>=0){
            k--;
            if(k==0){
                k=3;
            }
            else{ 
                ans+=cost[i];
            }
            i--;
        }
        return ans;
    }
};