class Solution {
public:
    int almostk(vector<int>& nums, int k){
        int left=0, right=0, count=0; 
        unordered_map<int,int> freq;
        int x=0;
        while(left<=right && right<nums.size()){
            if(freq[nums[right]]==0) x++;
            freq[nums[right]]++;
            if(x>k){
                while(x>k){
                    freq[nums[left]]--;
                    if(freq[nums[left]]==0) x--;
                    left++;
                }
            }
            count=count+right-left+1;
            right++;

        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return almostk(nums,k)-almostk(nums,k-1);
    }
};