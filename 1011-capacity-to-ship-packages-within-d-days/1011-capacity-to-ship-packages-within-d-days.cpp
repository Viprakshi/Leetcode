class Solution {
public:
    int cal(vector<int>& weights, int mid){
        int days=0, curr=0;
        for(int weight:weights){
            
            if(curr+weight<=mid){
                curr+=weight;
            }
            else{
                curr=weight;
                days++;
            }
            
        }
        if(curr) return days+1;
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(), weights.end());
        int high=0, mid;
        int ans;
        for(int weight: weights) high+=weight;

        while(low<=high){
            mid=(low+high)/2;
            if(cal(weights,mid)<=days){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};