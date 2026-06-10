class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int first=-1, last=-1;
        int left=0, right=nums.size()-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(nums[mid]>=target){
                if(nums[mid]==target){
                    first=mid;
                    last=mid;
                } 
                right=mid-1;
                
            }
            else{
                left=mid+1;
            }
        }
        while(last<nums.size() && last!=-1 && nums[last]==target) last++;
        if(last!=-1) last--;
        ans.push_back(first);
        ans.push_back(last);
        return ans; 
    }
};