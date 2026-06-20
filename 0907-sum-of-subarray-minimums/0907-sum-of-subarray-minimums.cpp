class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        long long ans = 0;
        int n = arr.size();
        const int MOD = 1e9 + 7;

        stack<int> st;

        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || arr[st.top()] >= arr[i])) {
                int mid = st.top();
                st.pop();

                int left = st.empty() ? -1 : st.top();
                int right = i;

                ans += 1LL * arr[mid] * (mid - left) * (right - mid);
                ans %= MOD;
            }
            st.push(i);
        }

        return ans;
    }
};