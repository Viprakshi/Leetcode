class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        
        if(nums.size()==1)return nums[0];
        if(nums[0]!=nums[1]) return nums[0];
        if(nums[n-1]!=nums[n-2]) return nums[n-1];
        int left=1, right=n-2;
        while(left<=right){
            int mid=(left+right)/2;
            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]) return nums[mid];
            else if(mid%2==0){ //even
                if(nums[mid]==nums[mid+1]){
                    //even,odd --> eliminate left
                    left=mid+1;
                }
                else{
                    //odd,even ---> eliminate right
                    right=mid-1;
                }
            } 
            else{
                //mid is odd
                if(nums[mid]==nums[mid+1]){
                    //odd, even --> eliminate right
                    right=mid-1;
                }
                else{
                    //even, odd ---> eliminate left
                    left=mid+1;
                }
            }
        }
        return -1;
    }
};