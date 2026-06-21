class Solution {
public:
    long long submin(vector<int>& arr){
        int n=arr.size();
        long long ans=0;
        
        stack<int> st;
        for(int i=0;i<=n;i++){
            while(!st.empty() && (i==n || arr[st.top()]>=arr[i])){
                int mid=st.top();
                st.pop();
                int left;
                if(st.empty()) left=-1;
                else left=st.top();
                int right=i;
                ans+=1LL*arr[mid]*(mid-left)*(right-mid);
            }
            st.push(i);

        }
        return ans;
    }
    long long submax(vector<int>& arr){
        int n=arr.size();
        stack<int> st;
        long long ans=0;
        for(int i=0;i<=n;i++){
            while(!st.empty() && (i==n || arr[st.top()]<=arr[i])){
                int mid=st.top();
                st.pop();
                int left;
                if(st.empty()) left=-1;
                else  left=st.top();
                int right=i;
                ans+=1LL*arr[mid]*(mid-left)*(right-mid);
            }
            st.push(i);
        }
        return ans;
    }
    long long subArrayRanges(vector<int>& nums) {
        return submax(nums)-submin(nums);
    }
};