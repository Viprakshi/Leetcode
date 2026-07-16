class Solution {
public:
    int trap(vector<int>& height) {
        int right=height.size()-1, left=0;
        int right_max=height[right], left_max=height[left];
        int ans=0;
        while(left<=right){
            if(height[left]>height[right]){
                    right_max=max(height[right],right_max);
                    ans+=right_max-height[right];
                    right--;
            }
            else{
                left_max=max(left_max, height[left]);
                ans+=left_max-height[left];
                left++;
            }
        }
        return ans;
    }
};