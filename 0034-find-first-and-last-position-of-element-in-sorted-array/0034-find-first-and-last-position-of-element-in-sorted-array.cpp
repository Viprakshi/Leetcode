class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first=-1, last=-1;
        //first=smallest index==target
        int left=0, right=nums.size()-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(nums[mid]>=target){
                if(nums[mid]==target) first=mid;
                right=mid-1;
            }
            else left=mid+1;
        }
        //last=greatest index==target
        last=first;
        while(last>=0 && last<nums.size() && nums[last]==target) last++;
        if(last>=1) last--;
        return {first, last};
    }
};