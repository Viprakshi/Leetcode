class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for(int num:nums){
            if(num%2==0) ans.push_back(-1);
            else{
                int x = num;
                int pos = 0;
                while((num >> pos) & 1) {
                    pos++;
                }
                x = num & ~(1 << (pos - 1));
                ans.push_back(x);
            }
        
        }
        return ans;
    }
};