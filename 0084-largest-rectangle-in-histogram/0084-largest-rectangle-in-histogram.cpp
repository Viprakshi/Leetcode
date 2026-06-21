class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans=0;
        stack<int> st;
        for(int i=0;i<heights.size();i++){
            int curr=heights[i];
            if(st.empty() || curr>heights[st.top()]){
                st.push(i);
                ans=max(ans, heights[i]);
                continue;
            }
            while(!st.empty() && curr<=heights[st.top()]){
                int nse=i;
                int c=heights[st.top()];
                st.pop();
                int pse;
                if(st.empty()) pse=-1;
                else pse=st.top();
                
                ans=max(ans,(c*(nse-pse-1)));
                
            }
            st.push(i);
        }
        while(!st.empty()){
            int nse = heights.size();
            int c = heights[st.top()];
            st.pop();

            int pse;
            if(st.empty()) pse = -1;
            else pse = st.top();

            ans = max(ans, c * (nse - pse - 1));
        }
        return ans;
    }
};