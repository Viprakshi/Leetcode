class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int ans=0;
        int left=0, right=0; 
        while(left<=right && right<s.length()){
            if(st.find(s[right])!=st.end()){
                while(st.find(s[right])!=st.end()){
                    st.erase(s[left]);
                    left++;
                }   
            }
            st.insert(s[right]);            
            ans=max(ans, right-left+1);
            right++;
        }
        return ans;
    }
};