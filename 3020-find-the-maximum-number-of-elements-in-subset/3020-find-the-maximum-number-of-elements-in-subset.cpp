class Solution {
public:
    unordered_map<long long,int> mpp;
    int cal(vector<int>& nums, long long x){
        if (x == 1) {
            int cnt = mpp[1];
            return (cnt % 2 == 0) ? cnt - 1 : cnt;
        }
        int len=2;
        long long curr=x;
        while(true){
            curr=curr*curr;
            if(mpp.find(curr)==mpp.end()) break;
            else if(mpp[curr]>=2){
                len+=2;
                
            }
            else{
                len++;
                break;
            }
            
        }
        if(len%2==0) len--;
        return len;
    }
    int maximumLength(vector<int>& nums) {
        //sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            int len;
            if(mpp[nums[i]]>=2){
                len=cal(nums, nums[i]);
                if(len==2) len--;
            }
            else len=1;
            maxi=max(maxi,len);
        }
        return maxi;

    }
};