class Solution {
public:
    int calculate(int divisor, int threshold, vector<int>& nums){
        int val=0;
        for(int num: nums){
            val+=ceil((double)num/divisor);
        }
        return val;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left=1, right=*max_element(nums.begin(),nums.end());
        int ans=-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            int value=calculate(mid,threshold,nums);
            if(value<=threshold){
                ans=mid;
                right=mid-1;
            }
            else left=mid+1;

        }
        return ans;
    }
};