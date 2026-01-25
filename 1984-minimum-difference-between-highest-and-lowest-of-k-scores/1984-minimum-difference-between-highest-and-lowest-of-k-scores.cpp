class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int sum=INT_MAX;
        for(int i=0;i<=nums.size()-k;i++){
            int left=i, right=i+k-1; 
            sum=min(sum,nums[right]-nums[left]); 
        }   
        return sum;
    }
};