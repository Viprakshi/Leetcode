class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        for(int j=0;j<nums.size();j++){
            if(nums[i]==nums[j]) continue;
            else{
                i++;
                nums[i]=nums[j];
            }
        }
        return i+1;
    }
};