class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int x=(2*nums.size())-1;
        stack<int> st;
        vector<int> ans(nums.size());
        for(int i=x;i>=0;i--){
            int y=nums[i % nums.size()];
            while(!st.empty() && st.top()<=y)
                st.pop();
            if(i<nums.size()){
                if(st.empty()) ans[i]=-1;
                else ans[i]=st.top();
            }
            st.push(y);
        }
        return ans;
    }
};