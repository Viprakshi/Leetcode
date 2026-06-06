class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int> left_sum(n,0);
        vector<int> right_sum(n,0);
        for(int i=1;i<n;i++){
            left_sum[i]=nums[i-1]+left_sum[i-1];
        }
        for(int i=n-2;i>=0;i--){
            right_sum[i]=nums[i+1]+right_sum[i+1];
        }
        for(int i=0;i<n;i++){
            int x=left_sum[i]-right_sum[i];
            if(x<0) x=x*-1;
            left_sum[i]=x;
        }
        return left_sum;
    }
};