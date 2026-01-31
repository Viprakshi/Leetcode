class Solution {
public:
    int countElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int smallest=nums[0];
        int largest=nums[nums.size()-1];
        int count=0;
        for(int i=1;i<nums.size()-1;i++){
            if(nums[i]>smallest && nums[i]<largest) count++;
        }
        return count;
    }
};