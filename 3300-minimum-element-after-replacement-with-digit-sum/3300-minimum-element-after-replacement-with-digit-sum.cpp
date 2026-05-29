class Solution {
public:
    int calsum(int num){
        int x=num, sum=0;
        while(x!=0){
            sum+=x%10;
            x=x/10;
        }
        return sum;
    }
    int minElement(vector<int>& nums) {
        int m=INT_MAX;
        for(int i=0;i<nums.size();i++){
            int s=nums[i];
            if(nums[i]>9){
                s=calsum(nums[i]);
                nums[i]=s;
            }
            m=min(m,s);
        }
        return m;
    }
};