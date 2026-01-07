class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1,mid, pos1=-1;
        while(low<=high){
            mid=(low+high)/2;
            if(nums[mid]==target){
                pos1=mid;
                high=mid-1;
            }
            if(nums[mid]<target){
                low=mid+1;
            }
            if(nums[mid]>target){
                high=mid-1;
            }
        }
       
        low=0,high=nums.size()-1,mid;
        int pos2=-1;
        while(low<=high){
            mid=(low+high)/2;
            if(nums[mid]==target){
                pos2=mid;
                low=mid+1;
            }
            if(nums[mid]<target){
                low=mid+1;
            }
            if(nums[mid]>target){
                high=mid-1;
            }
        }
        
        return {pos1,pos2};
    }
};