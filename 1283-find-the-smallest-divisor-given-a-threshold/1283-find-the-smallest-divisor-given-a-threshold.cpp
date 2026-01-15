class Solution {
public:
    int div(vector<int>& nums, int mid){
        int val=0;
        for(int num: nums){
            val+=ceil((double)num/mid);
        }
        return val;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1, high=*max_element(nums.begin(), nums.end());
        int mid=0,ans=0;

        while(low<=high){
            mid=(low+high)/2;
            if(div(nums,mid)<=threshold){
                ans=mid;
                high=mid-1;
            } 
            if(div(nums,mid)>threshold){
                low=mid+1;
            }
            
       }
       return ans;
    }
};