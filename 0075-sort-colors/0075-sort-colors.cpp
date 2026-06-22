class Solution {
public:
    void sortColors(vector<int>& nums) {
        int j=0,k=nums.size()-1;
        while(k<nums.size() && nums[k]==2) k--;
        while(j<nums.size() && nums[j]==0)j++;
        int i=0;
        while(i<nums.size() && nums[i]==0) i++;
        while(i<nums.size() && j<nums.size() && k>=0 && i<=k){
            if(nums[i]==0){
                swap(nums[i],nums[j]);
                j++;
                i++;
            } 
            else if(nums[i]==2){
                 swap(nums[i],nums[k]);
                 k--;
            }
            else i++;
        }

    }
};