class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int x=nums.size()-1;
        while(x>0 && nums[x]<=nums[x-1] ){
            x--;
        }
        if(x==0){
            reverse(nums.begin(),nums.end());
        }
        else{
            sort(nums.begin()+x, nums.end());
            int y=x-1;
            while(x<nums.size() && nums[x]<=nums[y]) x++;
            swap(nums[x],nums[y]);
        }
        
    }
};