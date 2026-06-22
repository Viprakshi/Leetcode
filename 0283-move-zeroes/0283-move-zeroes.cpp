class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j=0;
        int x=0;
        while(x<nums.size() && nums[x]!=0){
            x++;
        }
        if(x==nums.size()) return;
        j=x;
        for(int i=j+1;i<nums.size();i++){
            if(nums[i]!=0){
                swap(nums[i],nums[j]);
                j++;
            }            
        }
        
    }
};