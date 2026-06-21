class Solution {
public:
    bool check(vector<int>& nums) {
        int drops=0;
        for(int i=0;i<=nums.size()-1;i++){
            if(nums[i]>nums[(i+1)%nums.size()]) drops++;
        }
        if(drops<=1) return true;
        return false;
    }
};