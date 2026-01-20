class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left=0, right=0, sum=nums[0];
        int len=INT_MAX;
        while(left<=right && left<nums.size() && right<nums.size()){
            if(sum>=target){
                len=min(len,(right-left+1));
                sum-=nums[left];
                left++;
                
            }
            else{
                right++;
                if(right>=nums.size()) break;
                sum+=nums[right];               
            }
        }
        if(len==INT_MAX) return 0;
        return len;
        
    }
};