class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps=0; 
        int max_dis=0;
        int last=0;
        for(int i=0;i<nums.size()-1;i++){
            max_dis=max(max_dis, i+nums[i]);
            if(i==last){
                jumps++;
                last=max_dis;
            }
        }
        return jumps;
    }
};