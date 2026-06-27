class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int x=-1;
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                x=i;
                break;
            }

        }
        if(x==-1) reverse(nums.begin(),nums.end());
        else{
            sort(nums.begin()+x+1, nums.end());
            for(int i=x+1;i<nums.size();i++){
            if(nums[i]>nums[x]){
                swap(nums[i],nums[x]);
                break;
            }
        }
        }
        
    }
};