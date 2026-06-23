class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1=0, cnt2=0, elem1, elem2;
        for(int i=0;i<nums.size();i++){
            if(cnt1==0 && nums[i]!=elem2){
                elem1=nums[i];
                cnt1++;
            }
            else if(cnt2==0 && nums[i]!=elem1){
                elem2=nums[i];
                cnt2++;
            }
            else if(nums[i]==elem1) cnt1++;
            else if(nums[i]==elem2) cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }
        int x=0, y=0;
        for(int num:nums){
            if(num==elem1) x++;
            if(num==elem2) y++;
        }
        vector<int> ans;
        if(x>nums.size()/3) ans.push_back(elem1);
        if(y>nums.size()/3) ans.push_back(elem2);
        return ans;
    }
};