class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int i=0, p=-1, q=-1;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]) return false;
            if(nums[i]>nums[i+1]){
                p=i;
                break;
            }
        }
        for(int j=p;j<nums.size()-1;j++){
            if(nums[j]==nums[j+1]) return false;
            if(nums[j]<nums[j+1]){
                q=j;
                break;
            }
        }
        for(int k=q+1;k<nums.size()-1;k++){
            
            if(nums[k]>=nums[k+1]) return false;
        }
        if(p==-1 || q==-1 || p==0 || p==nums.size()-1 )return false;
        return true;
    }
};