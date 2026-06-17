class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n=nums.size();
        long long x=0;
        for(int num:nums){
            x=x^num;
        }
        long long rightmost=(x & (x -1))^x;
        int xor1=0, xor2=0;
        for(int i=0;i<n;i++){
            if(nums[i] & rightmost) xor1=xor1^nums[i];
            else xor2=xor2^nums[i];
        }
        if(xor1>xor2) return {xor2,xor1};
        return {xor1,xor2};
    }
};