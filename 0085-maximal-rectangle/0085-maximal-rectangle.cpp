class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        stack<int> st;

        for(int i = 0; i < heights.size(); i++) {
            while(!st.empty() && heights[i] <= heights[st.top()]) {
                int h = heights[st.top()];
                st.pop();

                int pse = st.empty() ? -1 : st.top();
                ans = max(ans, h * (i - pse - 1));
            }
            st.push(i);
        }

        while(!st.empty()) {
            int h = heights[st.top()];
            st.pop();

            int pse = st.empty() ? -1 : st.top();
            ans = max(ans, h * ((int)heights.size() - pse - 1));
        }

        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;

        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> heights(m, 0);
        int ans = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == '1')
                    heights[j]++;
                else
                    heights[j] = 0;
            }

            ans = max(ans, largestRectangleArea(heights));
        }

        return ans;
    }
};