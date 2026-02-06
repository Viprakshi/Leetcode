
class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        if(nums.size()==1) return 0;
        sort(nums.begin(), nums.end());
        int len=0;
        int i=0, j=1;
        while(j<nums.size() && i<=j){
            long long x= (long long)nums[i]*k;
            if(nums[j]<=x){
                len=max(len, j-i+1);
                j++;
            }
            else{
                i++;
            }
        }
        return nums.size()-len;
    }
};