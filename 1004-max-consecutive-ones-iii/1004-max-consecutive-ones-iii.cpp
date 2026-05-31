class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left=0, right=0, changed=0;
        int ans=0;
        while(left<=right && right<nums.size()){
            if(nums[right]==0){
               changed++;
               if(changed>k){
                while(changed>k){
                    if(nums[left]==0) changed--;
                    left++;
                }
               }
               

            }
            ans=max(ans, right-left+1);
            right++;
        }
        return ans;
    }
};