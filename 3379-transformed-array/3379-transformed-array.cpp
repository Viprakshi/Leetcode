class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n);
        for(int i=0; i<n;i++){
            if(nums[i]>0){
                int x=(i+nums[i])%n;
                res[i]=nums[x];
            }
            else if(nums[i]<0){
                int x=(((i-abs(nums[i])))%n);
                if(x < 0) x += n;
                res[i]=nums[x];
            }
            else{
                res[i]=nums[i];
            }
        }
        return res;
    }
};