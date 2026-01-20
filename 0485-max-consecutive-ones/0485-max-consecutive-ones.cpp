class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int len=0, ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1) len++;
            if(nums[i]==0){
                ans=max(ans,len);
                len=0;
            }
        }
        ans=max(ans,len);
        return ans;
        
    }
};