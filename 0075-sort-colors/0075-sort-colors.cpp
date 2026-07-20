class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i=0,j=0, k=nums.size()-1;
        while(i<nums.size() && nums[i]==0){
            i++;
            j++;
        }
        while(k>=0 && nums[k]==2) k--;
        while(i<=j && j<=k){
            if(nums[j]==0){
                swap(nums[i],nums[j]);
                i++;
                j++;
            }
            else if(nums[j]==2){
                swap(nums[j],nums[k]);
                k--;
            }
            else{
                j++;
            }
            
        }
    }
};