class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left=0, right=nums.size()-1;
        int insert_at=nums.size();
        //smallest index that is greater than or equal to my target 
        while(left<=right){
            int mid=(left+right)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                right=mid-1;
                insert_at=mid;
            }
            else{
                left=mid+1;
            }
        }
        return insert_at;
    }
};