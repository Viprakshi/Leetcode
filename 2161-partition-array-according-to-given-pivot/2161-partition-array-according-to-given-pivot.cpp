class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int more_than=0;
        for(int i=0; i<nums.size();i++){
            if(nums[i]>pivot) more_than++;
        }
        int left=0, right=nums.size()-more_than;
        vector<int> ans(nums.size(), INT_MIN);
        for(int i=0;i<nums.size();i++){
            if(nums[i]<pivot){
                ans[left]=nums[i];
                left++;
            }
            else if(nums[i]>pivot){
                ans[right]=nums[i];
                right++;
            }
        }
        while(left<nums.size() && ans[left]==INT_MIN){
            ans[left]=pivot;
            left++;
        }
        return ans;
    }
};