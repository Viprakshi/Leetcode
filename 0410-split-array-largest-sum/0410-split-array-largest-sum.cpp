class Solution {
public:
    bool cansplit(vector<int>& nums, int k, int mid){
        int sub=0;
        int cnt=1;
        for(int i=0;i<nums.size();i++){
            if(sub+nums[i]<=mid){
                sub=sub+nums[i];
            }
            else{
                cnt++;
                if(cnt>k) return false;
                sub=nums[i];
            }
        }
        return true;

    }
    int splitArray(vector<int>& nums, int k) {      
        int left=*max_element(nums.begin(), nums.end()), right=accumulate(nums.begin(), nums.end(),0);
        int ans=-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(cansplit(nums,k,mid)){
                ans=mid;
                right=mid-1;
            }
            else left=mid+1;
        }
        return ans;        
    }
};