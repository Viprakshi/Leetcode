class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n), right(n);
        stack<int> st;
        int mod = 1e9+7;

        // Previous Smaller Element
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i])
                st.pop();

            if(st.empty()) left[i]=-1;
            else left[i]=st.top();

            st.push(i);
        }

        while(!st.empty()) st.pop();

        // Next Smaller or Equal Element
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i])
                st.pop();

            if(st.empty()) right[i]=n;
            else right[i]=st.top();

            st.push(i);
        }

        long long ans=0;

        for(int i=0;i<n;i++){
            long long leftCount=i-left[i];
            long long rightCount=right[i]-i;
            ans=(ans+1LL*arr[i]*leftCount*rightCount)%mod;
        }

        return ans;
    }
};