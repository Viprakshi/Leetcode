class Solution {
public:
    vector<int> find_nse(vector<int>& arr){
        stack<int> st;
        vector<int> ans(arr.size());
        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()) ans[i]=arr.size();
            else ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> find_pse(vector<int>& arr){
        stack<int> st;
        vector<int> ans(arr.size());
        for(int i=0;i<arr.size();i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            if(st.empty()) ans[i]=-1;
            else ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> nse=find_nse(heights);
        vector<int> pse=find_pse(heights);
        int ans=0;
        for(int i=0;i<heights.size();i++){
            ans=max(ans,heights[i]*(nse[i]-pse[i]-1));
        }
        return ans;
    }
};