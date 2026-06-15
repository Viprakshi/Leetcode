class Solution {
public:
    bool cansplit(vector<int>& nums, int k, int mid){
        int arr=1;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>mid) return false;
            if(sum+nums[i]>mid){
                arr+=1;
                sum=nums[i];
                if(arr>k) return false;
            }
            else{
                sum+=nums[i];
            }
        }
        return true;

    }
    int splitArray(vector<int>& nums, int k) {
        
        int left=0, right=accumulate(nums.begin(), nums.end(),0);
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