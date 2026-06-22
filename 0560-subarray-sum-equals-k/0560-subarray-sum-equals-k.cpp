class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        int sum=0;
        int ans=0;
        mpp[0]=1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(mpp.find(sum-k)!=mpp.end()){
                ans+=mpp[sum-k];
            }
            mpp[sum]++;            
        }
        return ans;
    }
};