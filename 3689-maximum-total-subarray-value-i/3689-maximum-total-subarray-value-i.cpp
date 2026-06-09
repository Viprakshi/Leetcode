class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long maxi = LLONG_MIN;
        long long mini = LLONG_MAX;
        for(int num:nums){
            maxi=max(maxi,(long long)num);
            mini=min(mini,(long long)num);
        }
        
         return (long long)k * (maxi - mini);

    }
};