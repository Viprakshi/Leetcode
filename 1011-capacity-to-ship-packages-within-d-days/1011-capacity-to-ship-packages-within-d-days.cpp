class Solution {
public:
    int count_days(int weight_given, vector<int>& weights){
        int days=1;
        int x=0;
        for(int weight:weights){
            if(x+weight<=weight_given)
            x+=weight;
            else{
                days++;
                x=weight;
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
               
        int left=*max_element(weights.begin(),weights.end()), right=accumulate(weights.begin(),weights.end(),0);
        int ans=right;
        while(left<=right){
            int mid=(left+right)/2;
            int days_required=count_days(mid, weights);
            if(days_required<=days){
                ans=mid;
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return ans;
    }
};