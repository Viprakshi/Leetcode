class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int curr=nums[0], x=0;
        for(int i=0;i<nums.size();i++){
            if(x==0){
                curr=nums[i];
                x=1;
            } 
            else if(nums[i]==curr)x++;
            else x--;
        }
        return curr;
    }
};