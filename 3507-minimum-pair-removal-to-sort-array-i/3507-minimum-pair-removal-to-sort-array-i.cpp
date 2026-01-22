class Solution {
public:
    bool is_sorted(vector<int>& nums){
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]) return false;
        }
        return true;
    }
    int minimumPairRemoval(vector<int>& nums) {
        
        int ans=0,x,y;
        while(is_sorted(nums)==false){
            int min_sum=INT_MAX;
            for(int i=nums.size()-1;i>0;i--){
                if(nums[i]+nums[i-1]<=min_sum){
                    min_sum=nums[i]+nums[i-1];
                    x=i, y=i-1;
                }
            }
            nums.erase(nums.begin()+x);
                nums[y]=min_sum;
                ans++;
        }
        return ans;

    }
};